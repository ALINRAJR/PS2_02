/*
===============================================================================
 Name        : 22_Day54_03112021_PS2002.c

 Description : Program demonstrate PS2 device to host communication - counting the clock
 TESTCASE3   : Interrupt configured for EDGE_SENSITIVE and FALLING_EDGE

 TODO        :

 Layered Architecture used for this project
 ************************************
 Application layer-22_Day54_03112021_PS2002.c
 ************************************
 Board layer - ps2protocol.c/.h, configboard.h
 ************************************
 Low level drivers or chip level - pinmux.c/.h,extint.c/.h, gpio.c/.h
 ************************************
 Hardware
 ************************************

===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "pinmux.h"
#include "lcd.h"
#include "ps2protocol.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{
	vPinmuxInitialize();
	vLCDInitialize();
	vLCDInitialCommands();
	vPS2IntInitialize();
}

/**
  * @brief  Crude Delay
  * @retval none
  */
void vAppDelay(uint32_t count)
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<0xA00;j++);
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();
   vLCDPrintf("PS2 TEST");

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {
		vLCDGotoxy(LINE1, COL0);
		vLCDPrintf("%x", ps2scandata[0]);
		vLCDGotoxy(LINE1, COL5);
		vLCDPrintf("%x", ps2scandata[1]);
		vLCDGotoxy(LINE1, COL10);
		vLCDPrintf("%x", ps2scandata[2]);

	 // vLCDPrintf("%d",ps2clkcount);
  }
  /* End of Application entry point */
}




