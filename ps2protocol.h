

#ifndef PS2PROTOCOL_H_
#define PS2PROTOCOL_H_

/* Private includes ----------------------------------------------------------*/
#include "configboard.h"
/* Private typedef -----------------------------------------------------------*/
enum {START_BIT=1,PARITY_BIT=10,STOP_BIT=11};
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
extern uint8_t ps2scandata[3];
/**
  * @brief Initializing the PS2 clock as external interrupt and data as digital input
  * @return None
  **/
void vPS2IntInitialize(void);


#endif /* PS2PROTOCOL_H_ */
