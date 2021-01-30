#include "DataType.h" 
#include "SystemConfig.h"
#include "Global.h"
#include "MsgMap.h"
#include "Osd_Menu.h" 
#include "Osd_MenuPage.h" 
#include "Osd_LogoFontDat.h"

UINT CODE LOGO1LogoMenuIcon[]=
{
   LogoIndexAddr_LOGO1
};
UINT * LOGO1LogoMenu_Icon(void)
{
   return  LOGO1LogoMenuIcon;
}
IconType  CODE  LOGO1LogoMenu_IconTab[]=
{
{ 0, 0,LogoWidth_LOGO1,LogoHeighth_LOGO1,TRANSPARENCE,TRANSPARENCE,LOGO1LogoMenu_Icon,osdEnd},
};
UINT CODE LOGO2LogoMenuIcon[]=
{
   LogoIndexAddr_LOGO2
};
UINT * LOGO2LogoMenu_Icon(void)
{
   return  LOGO2LogoMenuIcon;
}
IconType  CODE  LOGO2LogoMenu_IconTab[]=
{
{ 0, 0,LogoWidth_LOGO2,LogoHeighth_LOGO2,TRANSPARENCE,TRANSPARENCE,LOGO2LogoMenu_Icon,osdEnd},
};
UINT CODE LOGO3LogoMenuIcon[]=
{
   LogoIndexAddr_LOGO3
};
UINT * LOGO3LogoMenu_Icon(void)
{
   return  LOGO3LogoMenuIcon;
}
IconType  CODE  LOGO3LogoMenu_IconTab[]=
{
{ 0, 0,LogoWidth_LOGO3,LogoHeighth_LOGO3,TRANSPARENCE,TRANSPARENCE,LOGO3LogoMenu_Icon,osdEnd},
};
UINT CODE LOGO4LogoMenuIcon[]=
{
   LogoIndexAddr_LOGO4
};
UINT * LOGO4LogoMenu_Icon(void)
{
   return  LOGO4LogoMenuIcon;
}
IconType  CODE  LOGO4LogoMenu_IconTab[]=
{
{ 0, 0,LogoWidth_LOGO4,LogoHeighth_LOGO4,TRANSPARENCE,TRANSPARENCE,LOGO4LogoMenu_Icon,osdEnd},
};
UINT CODE LOGO5LogoMenuIcon[]=
{
   LogoIndexAddr_LOGO5
};
UINT * LOGO5LogoMenu_Icon(void)
{
   return  LOGO5LogoMenuIcon;
}
IconType  CODE  LOGO5LogoMenu_IconTab[]=
{
{ 0, 0,LogoWidth_LOGO5,LogoHeighth_LOGO5,TRANSPARENCE,TRANSPARENCE,LOGO5LogoMenu_Icon,osdEnd},
};
