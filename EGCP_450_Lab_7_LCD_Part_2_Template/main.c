// main.c
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include "SysTickInts.h"
#include "LCD.h"
#include "msp432p401r.h"

uint32_t ADCtoCM(void){
    return (0.00012227*SysTick_Mailbox()-0.0031)*1000;
}

void main() {
    LCD_Init();
    SysTick_Init(75000);                // 25000us
    LCD_OutString("EGCP 450 Lab 7");
    delay(100000);
    LCD_OutCmd(0xC0);                   // next line
    while(1){
        LCD_OutUFix(ADCtoCM());
        LCD_OutString("cm");
        LCD_OutCmd(0xC0);
    }
}

