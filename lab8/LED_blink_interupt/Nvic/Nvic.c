

#include "Nvic.h"

#include "Bit_Operations.h"

#define NVIC_BASE (0xE000E100)



#define NVIC_REG(index) (*(uint32 *)(index))  

uint32 NVIC_ISER_addresses[3] = {0xE000E100 /* NVIC_ISER0*/, 0xE000E104 /*NVIC_ISER1*/ , 0xE000E108};
uint32 NVIC_ICER_addresses[3] = {0xE000E180 , 0xE000E184 , 0xE000E188};


void Nvic_EnableInterrupt(uint8 IRQn) {
if(IRQn<96){

    SET_BIT(NVIC_REG(NVIC_ISER_addresses[IRQn / 32]),IRQn - 32*(IRQn / 32)); 
  }  // TODO: use arrays and pointers to remove this if else statement
  // if (IRQn>=0 && IRQn < 32) {// irqn = 6 means i am enabling of line 6 in  the nvic
  //   SET_BIT(NVIC_ISER0, IRQn);
  // } else if (IRQn >= 32 &&IRQn < 64) {
  //    SET_BIT(NVIC_ISER1, IRQn - 32);// -32 coz i wanna set the bit of the (IRQn - 32*i)
  // } else if (IRQn >= 64 && IRQn < 96) {
  //   SET_BIT(NVIC_ISER2, IRQn - 64);
  // }
}

void Nvic_DisableInterrupt(uint8 IRQn) {
  if(IRQn<96){

    // TODO: use arrays and pointers to remove this if else statement
      SET_BIT(NVIC_REG(NVIC_ICER_addresses[IRQn / 32]), IRQn - 32*(IRQn / 32)); // (IRQn / 32) is the index of the NVIC_ICER
  }
  // if (IRQn < 32) {
  //   SET_BIT(NVIC_ICER0, IRQn);
  // } else if (IRQn < 64) {
  //   SET_BIT(NVIC_ICER1, IRQn - 32);
  // } else if (IRQn < 96) {
  //   SET_BIT(NVIC_ICER2, IRQn - 64);
  // }
}
