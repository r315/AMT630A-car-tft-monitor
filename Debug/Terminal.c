
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
static UINT atoh(UCHAR *str){
    UINT val = 0;
    char c = *str;
    
    do {
        val <<= 4;
        if (c > '`' && c < 'g') {
            c -= 'W';
        }
        else if ((c > '@' && c < 'G')) {
            c -= '7';
        }
        else if (c > '/' && c < ':') {
            c -= '0';
        }
        else {
            return 0;
        }

        val |= c;
        c = *(++str);

    } while (c != '\0' && c != ' ' && c != '\n' && c != '\r');

    return val;    
}

/** ***********************************************************
 * 
 * 
 * *********************************************************** */
void TERM_Handler(){
    
    UINT XDATA value1, value2;
    UCHAR XDATA rcv;

    if(fifo_get(&l_rx, &rcv) == FALSE){        
        return;
    }

    fifo_put(&l_tx, rcv);

    switch(rcv){
        case '\n':
        {
            l_buf[l_idx] = '\0';    
            l_idx = 0;

            switch(l_buf[0]){
                case 'r':
                    value1 = atoh(&l_buf[1]);
                    value2 = CBYTE[value2];
                    xprintf("\nADDR %04X = %02X\n", value1, value2);
                    break;

                default: 
                    break;
            }
            break;
        }

        case 'b':
        {
            if(g_bBackLightFlg){
                TurnOffBackLight();
            }else{
                TurnOnBackLight();
            }
            break;
        }

        case '4':
        {
            l_msg = MSG_UPK_MENU;
            break;
        }

        case '2':
        {
            l_msg = MSG_UPK_LEFT;
            break;
        }

        case '3':
        {
            l_msg = MSG_UPK_RIGHT;
            break;
        }

        case 's':
        {
            l_msg = MSG_UPK_SOURCE_SWITCH;
            break;
        }

        case 'c':
        {
            l_msg = MSG_UPK_BRIGHTNESS;
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

void putchar(UCHAR ucVal)
{	
    fifo_put(&l_tx, ucVal);
    TI = ON;
}

void printfStr(char *str){
 BYTE XDATA ucBff;

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
#if 1
    xprintf(str,value);
#else    
char XDATA sendData;

      fifo_put(&l_tx,(char)'\r');
      fifo_put(&l_tx,(char)'\n');
    
      while(sendData=*(str++))
    {
        if (sendData==(char)'%') 
        {
            sendData=*(str++);
              if (sendData==(char)'d' || sendData==(char)'x') 
            {
                if (value)
                {
                    BOOL noneZero=FALSE;
                      WORD divider=10000;
                      char dispValue;

                      if (sendData==(char)'x')
                        divider=0x1000;
                      while (divider)
                    {
                        dispValue=value/divider;
                          value-=dispValue*divider;
                        if (dispValue)
                              noneZero=TRUE;
                        if (noneZero)
                        {
                            if (dispValue>9)
                                 dispValue+=55;
                               else
                                dispValue+=0x30;
                             fifo_put(&l_tx, dispValue);
                          }
                        if (sendData==(char)'d')
                              divider/=10;
                          else
                             divider/=0x10;
                    }
                }
                  else
                  {
                      fifo_put(&l_tx, '0');
                  }	
              }
          }
          else
            fifo_put(&l_tx, sendData);
    }
    TI = ON;
#endif
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
    SBYTE XDATA d, r, pad, lz;
	CHAR XDATA *p;
    SINT value;
	char XDATA *arp = (char*)&fmt + sizeof(fmt);
   
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