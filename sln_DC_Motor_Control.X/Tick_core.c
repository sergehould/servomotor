/* 
 * File: Tick_core.c
 * Description: 
 *      Tick library implemented using the 32-bit core timer.
 *      The core timer increments once for every two ticks of SYSCLK
 *      For a SYSCLK of 80 MHz, the timer increments every 25 ns. 
 *      Because the timer is 32 bits, it rolls over every 
 *      232 × 25 ns = 107 s.
 * 
 * Author   Date            Comments
 * SH       28 Jan 2021    

 **/
#include <xc.h>
#include <stdint.h>
#include "Tick_core.h"

/* Blocking delay function */
void delay_us(unsigned int us)
{
    // Convert microseconds us into how many clock ticks it will take
    us *= SYS_FREQ / 1000000 / 2; // Core Timer updates every 2 ticks

    _CP0_SET_COUNT(0); // Set Core Timer count to 0

    while (us > _CP0_GET_COUNT()); // Wait until Core Timer count reaches the number we calculated earlier
}

/* Gets the core timer current tick value */
int64_t TickGet(void){
    return _CP0_GET_COUNT();
}

/* Reset the core timer to 0 */
void TickCoreReset(void){
        _CP0_SET_COUNT(0); // Set Core Timer count to 0
}