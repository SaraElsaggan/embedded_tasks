
#include "Std_Types.h"
// Define the edge types for triggering EXTI interrupts
#define RISING_EDGE 'r'
#define FALLING_EDGE 'f'
#define RISING_AND_FALLING_EDGE 'r&f'

// Base address for EXTI peripheral
#define EXTI ((ExtiType *)0x40013C00)

// Define the addresses of the SYSCFG EXTICR registers
#define SYSCFG_EXTICR1 (*(uint32 *)(0x40013800 + 0x08))
#define SYSCFG_EXTICR2 (*(uint32 *)(0x40013800 + 0x0c))
#define SYSCFG_EXTICR3 (*(uint32 *)(0x40013800 + 0x10))
#define SYSCFG_EXTICR4 (*(uint32 *)(0x40013800 + 0x14))


// Define a structure that represents the EXTI registers
typedef struct
{
	uint32 IMR;	  
	uint32 EMR;	  
	uint32 RTSR;  
	uint32 FTSR;  
	uint32 SWIER; 
	uint32 PR;	  
} ExtiType;


void Exti_Init(uint8 GPIO_PORT, uint32 pinNumber, uint32 trigger_edgeDetection);
void Exti_Disable(uint32 Exti_line);
void Exti_Enable(uint32 Exti_line);
