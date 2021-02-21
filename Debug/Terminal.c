
#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "MsgMap.h"
#include "AMT_Drv.h"
#include "AMT_Mcu.h"
#include "AMT_Reg.h"
#include "Debug.h"

#define _TERMINAL_C_

#ifdef UartTerminal

#define FIFO_SIZE  128

typedef struct {
    BYTE head;
    BYTE tail;
    UCHAR buf[FIFO_SIZE];
} fifo_t;

static fifo_t XDATA l_rx, l_tx;
static UCHAR XDATA l_buf[10], l_idx;
static MSG XDATA l_msg;

void fifo_init(fifo_t *fifo)
{
    fifo->head = 0;
    fifo->tail = 0;
}

BOOL fifo_put(fifo_t *fifo, UCHAR c) reentrant 
{
    BYTE next;

    // check if FIFO has room
    next = (fifo->head + 1) & (FIFO_SIZE - 1); //% FIFO_SIZE;
    if (next == fifo->tail) {
        // full
        return FALSE;
    }

    fifo->buf[fifo->head] = c;
    fifo->head = next;

    return TRUE;
}

BOOL fifo_get(fifo_t *fifo, UCHAR *pc) reentrant 
{
    BYTE next;

    // check if FIFO has data
    if (fifo->head == fifo->tail) {
        return FALSE;
    }

    next = (fifo->tail + 1) & (FIFO_SIZE - 1); //% FIFO_SIZE;

    *pc = fifo->buf[fifo->tail];
    fifo->tail = next;

    return TRUE;
}

BYTE fifo_avail(fifo_t *fifo) reentrant 
{
    return (FIFO_SIZE + fifo->head - fifo->tail) & (FIFO_SIZE - 1); //% FIFO_SIZE;
}

/*
BYTE fifo_free(fifo_t *fifo)
{
    return (FIFO_SIZE - 1 - fifo_avail(fifo));
}

void fifo_flush(fifo_t *fifo)
{
    fifo->head = 0;
    fifo->tail = 0;
}
UCHAR fifo_peek(fifo_t *fifo){
    return fifo->buf[fifo->tail];
}
*/
static UINT atoh(UCHAR **pstr){
    UINT val = 0;
    char *str = *pstr;
    char c = *str;
    
    do {
        if (c > '`' && c < 'g') {  // filter a,b,c,d,e,f
            c -= 'W';
        }
        else if ((c > '@' && c < 'G')) { // filter A,B,C,D,E,F
            c -= '7';
        }
        else if (c > '/' && c < ':') { // filter 0-9
            c -= '0';
        }
        else {
            break;
        }

        val <<= 4;
        val |= c;
        c = *(++str);

    } while (1); //(c != '\0' && c != ' ' && c != '\n' && c != '\r');

    *pstr = str;

    return val;    
}

/** ***********************************************************
 * 
 * 
 * *********************************************************** */
void TERM_Handler(){
    
    UINT XDATA value1, value2;
    UCHAR rcv;
    char *pstr;

    if(fifo_get(&l_rx, &rcv) == FALSE){        
        return;
    }

    fifo_put(&l_tx, rcv);

    switch(rcv){
        case '\n':
        {
            l_buf[l_idx] = '\0';    
            l_idx = 0;

            value1 = (l_buf[0] << 8) | l_buf[1];

            switch(value1){
                case ('r' << 8) + 'c':
                    pstr = &l_buf[2];
                    value1 = atoh(&pstr);
                    value2 = CBYTE[value1];
                    xprintf("CODE[%04X] = %02X\n", value1, value2);
                    break;                

                case ('r' << 8) + 'i':
                    pstr = &l_buf[2];
                    value1 = atoh(&pstr);
                    value2 = IBYTE[value1];
                    xprintf("IDATA[%02X] = %02X\n", value1, value2);
                    break;

                case ('r' << 8) + 'x':
                    pstr = &l_buf[2];
                    value1 = atoh(&pstr);
                    value2 = XBYTE[value1];
                    xprintf("XDATA[%04X] = %02X\n", value1, value2);
                    break;               

                case ('w' << 8) + 'x':
                    pstr = &l_buf[2];
                    value1 = atoh(&pstr);
                    pstr++;
                    value2 = atoh(&pstr);
                    XBYTE[value1] = (BYTE)value2;
                    xprintf("XDATA[%04X] = %02X\n", value1, value2);
                    break;

                case ('w' << 8) + 'i':
                    pstr = &l_buf[2];
                    value1 = atoh(&pstr);
                    pstr++;
                    value2 = atoh(&pstr);
                    IBYTE[value1] = (BYTE)value2;
                    xprintf("IDATA[%02X] = %02X\n", value1, value2);
                    break;

                default: 
                    break;
            }
            break;
        }

        case 'Z':
        {
            l_msg = MSG_UPK_MENU;
            break;
        }

        case 'F':
        {
            l_msg = MSG_UPK_POWER;
            break;
        }

        case 'X':
        {
            l_msg = MSG_UPK_MODE;
            break;
        }

        case 'C':
        {
            l_msg = MSG_UPK_SYS;
            break;
        }

        case 'W':
        {
            l_msg = MSG_UPK_UP;
            break;
        }

        case 'S':
        {
            l_msg = MSG_UPK_DOWN;
            break;
        }

        case 'A':
        {
            l_msg = MSG_UPK_LEFT;
            break;
        }

        case 'D':
        {
            l_msg = MSG_UPK_RIGHT;
            break;
        }

        case 'V':
        {
            l_msg = MSG_UPK_SOURCE_SWITCH;
            break;
        }        

        default :
        {
            if (rcv == '\b') {
                fifo_put(&l_tx, ' ');
                fifo_put(&l_tx, rcv);
                if(l_idx > 0){
                    l_idx--;
                }
            }else{
                l_buf[l_idx] = rcv;

                if(l_idx < sizeof(l_buf)){
                    l_idx++;
                }
            }

            break;
        }
    }
    
    TI = ON;
}

MSG POS_GetTermMsg(){
    MSG tmp;

    if(l_msg != MSG_NULL){
        tmp = l_msg;
        l_msg = MSG_NULL;
        g_UserInputInfo.Status = inputPress;
        return tmp;
    }

    return MSG_NULL;
}

void TERM_Init(void){    
    Uart_RXD();
    Uart_TXD();
    ES = ON;
    EA = ON;
    fifo_init(&l_rx);
    fifo_init(&l_tx);
    l_idx = 0;
}

void POS_UartTerminal(void){
    UCHAR d;

    if(RI){
        RI = 0;
        fifo_put(&l_rx, SBUF);
    }

    if(TI){
        TI = 0;
        if(fifo_avail(&l_tx)){
            fifo_get(&l_tx, &d);
            SBUF = d;
        }
    }
}

BOOL TERM_HasData(void){
    return fifo_avail(&l_rx) > 0;
}
/*
void putchar(UCHAR ucVal)
{	
    fifo_put(&l_tx, ucVal);
    TI = ON;
}
*/
void printfStr(char *str){
    BYTE ucBff;

    while(1)
    {
         ucBff = *str;
         if (ucBff == '\0')
             break;
         fifo_put(&l_tx, ucBff);
         str++;
    }

    fifo_put(&l_tx,(char)'\r');
    fifo_put(&l_tx,(char)'\n');

    TI = ON;
}

void printf(char *str, WORD value){
    xprintf(str,value);
}

#define XPITOA_BUF_SIZE         8
/**
 * \param ndig: 0 = no padding, > 0 = leading spaces, < 0 = leading zeros
 * */
void xpitoa(SINT val, SBYTE radix, SBYTE ndig)
{
    BYTE XDATA buf[XPITOA_BUF_SIZE];
    BYTE i, c, r, sgn, pad;
    UINT v;
	
    sgn = 0;
    pad = ' ';

    if (radix < 0) {
        radix = -radix;
        if (val < 0) {
            val = -val;
            sgn = '-';
        }
    }

    v = val;
    r = radix;

    if (ndig < 0) {
        ndig = -ndig;
        pad = '0';
    }

    if (ndig > XPITOA_BUF_SIZE) {
        ndig = XPITOA_BUF_SIZE;
    }

    ndig = XPITOA_BUF_SIZE - 1 - ndig;
    i = XPITOA_BUF_SIZE;
    buf[--i] = '\0';

    do {
        c = (BYTE)(v % r);
        if (c >= 10) c += 7;
        c += '0';
        buf[--i] = c;
        v /= r;
    } while (v);

    if (sgn) buf[--i] = sgn;

    while (i > ndig) {
        buf[--i] = pad;
    }

    while(buf[i]){
        fifo_put(&l_tx, buf[i++]);
    }
}

void xprintf(const char* fmt, ...)
{	
    SINT value;
    SBYTE d, r, pad;
    BIT lz;
	CHAR *p;
	char *arp = (char*)&fmt + sizeof(fmt);
   
    while ((d = *fmt++) != '\0') {

        if (d == '\0'){
            break;
        }

        r = pad = lz = 0;

        if (d != '%') {			
            fifo_put(&l_tx, d);
            continue;
        }

        d = *fmt++;

        if (d == 's') {     // Print string?            
            p = (char *)((arp += sizeof(char)) - sizeof(char));
            while(*p){
                fifo_put(&l_tx, *(p++));
            }
            continue;
        }

        if (d == 'c') {     // print char?
            fifo_put(&l_tx, *(char *)((arp += sizeof(char)) - sizeof(char)));
            continue;
        }

        // print number

        if (d == '0') {  // Add leading zeros?
            d = *fmt++;
            lz = 1;
        }

        // get padding size, if specified
        while ((d >= '0') && (d <= '9')) {
            pad += pad * 10 + (d - '0');
            d = *fmt++;
        }

        if (d == 'u') r = 10;
        if (d == 'd') r = -10;
        if (d == 'X' || d == 'x') r = 16;
        if (d == 'b') r = 2;		
        
        if (r == 0){
            // default radix
            r =  10;
        } 

        if (lz){
            pad = -pad;  
        } 
        
        if (r > 0){
            value = *(SINT*)((arp += sizeof(SINT)) - sizeof(SINT)); 
        }else{
            value = *(UINT*)((arp += sizeof(UINT)) - sizeof(UINT));
        }

        xpitoa(value, r, pad);        
    }

    //TI = ON;
    *arp = '\0';
}
#if TP0_RM
void IrqPrintf(char *str, WORD value){
    printf(str, value);
}
#endif

#ifdef ColorSysChangeBLOffEn
void IrqPutstr(UCHAR *pFmt){
    printfStr(pFmt);
}
#endif

#endif