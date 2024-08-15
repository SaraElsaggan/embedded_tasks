
#ifndef NVIC_H
#define NVIC_H

#include "Std_Types.h"


#define NVIC_BASE (*(uint32 *)0xE000E100)


        

#define NVIC_REG(index) (*(uint32 *)(index))  

uint32 NVIC_ISER_addresses[3] = {0xE000E100 , 0xE000E104 , 0xE000E108};
uint32 NVIC_ICER_addresses[3] = {0xE000E180 , 0xE000E184 , 0xE000E188};


void Nvic_EnableInterrupt(uint8 IRQn);

void Nvic_DisableInterrupt(uint8 IRQn);

#endif /* NVIC_H */
