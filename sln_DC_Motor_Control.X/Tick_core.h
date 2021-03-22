/* 
 * File:   Tick_core.h
 * Author: sh
 *
 * Created on January 28, 2021
 * SH               28 Jan 2021         
 */

#ifndef TICK_CORE_H
#define	TICK_CORE_H
//#include "initBoard.h"
#include <stdint.h>

//#define GetSystemClock()		(40000000ul)      // Hz	
#define     SYS_FREQ            40000000 // Running at 80MHz
#define     TICKS_PER_SECOND    SYS_FREQ 
void delay_us(unsigned int us);
int64_t TickGet(void);

void TickCoreReset(void);

#endif	/* PWM_H */

