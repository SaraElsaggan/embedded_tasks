
#include "Nvic.h"

#include "Bit_Operations.h"


void Nvic_EnableInterrupt(uint8 IRQn) {
  if(IRQn<96){
    SET_BIT(NVIC_REG(NVIC_ISER_addresses[IRQn / 32]),IRQn - 32*(IRQn / 32)); 
  }
}

void Nvic_DisableInterrupt(uint8 IRQn) {
  if(IRQn<96){
    SET_BIT(NVIC_REG(NVIC_ICER_addresses[IRQn / 32]), IRQn - 32*(IRQn / 32)); // (IRQn / 32) is the index of the NVIC_ICER
  }
}
