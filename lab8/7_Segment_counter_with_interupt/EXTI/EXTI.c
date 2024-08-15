
#include "EXTI.h"
#include "Bit_Operations.h"
#include "Rcc.h"
#include "Gpio.h"



void Exti_Init( uint8 GPIO_PORT,uint32 pinNumber, uint32 edge_type){

    if(edge_type==FALLING_EDGE){
            SET_BIT( EXTI->FTSR  , pinNumber);
    }
    else if (edge_type==RISING_EDGE){
            SET_BIT( EXTI->RTSR  , pinNumber);
    }
    else if(edge_type==RISING_AND_FALLING_EDGE){   

        SET_BIT( EXTI->FTSR  , pinNumber);
        SET_BIT( EXTI->RTSR  , pinNumber);

    }


/* Configure the SYSCFG external interrupt configuration registers (EXTICR) */
    uint8 port_id = GPIO_PORT - GPIO_A;
    
    uint32 *SYSCFG_EXTICR[4] = { &SYSCFG_EXTICR1, &SYSCFG_EXTICR2, &SYSCFG_EXTICR3, &SYSCFG_EXTICR4 };


    // Clear the EXTI line configuration
    *SYSCFG_EXTICR[pinNumber / 4] &= ~(0xf << ((pinNumber % 4) * 4)/*4 is num of bits*/);
    // Set the EXTI line configuration
    *SYSCFG_EXTICR[pinNumber / 4] |= (port_id << ((pinNumber % 4) * 4));


 if (pinNumber < 5) {
        // Direct mapping for EXTI0 to EXTI4
        Nvic_EnableInterrupt(6 + pinNumber);
    } else if (pinNumber < 10) {
        // Shared interrupt for EXTI5 to EXTI9
        Nvic_EnableInterrupt(23);
    } else if (pinNumber < 16) {
        // Shared interrupt for EXTI10 to EXTI15
        Nvic_EnableInterrupt(40);
    }

}



// enable specific EXTI line 
void Exti_Enable(uint32 Exti_line){
    SET_BIT(EXTI->IMR , Exti_line);

}

// disable specific EXTI line
void Exti_Disable(uint32 Exti_line) {
    CLEAR_BIT(EXTI->IMR , Exti_line);

}








