#include "EXTI.h"
#include "Gpio/Gpio.h"
#include "Rcc.h"
#include "Bit_Operations.h"

uint8 counter = 0;

int main()
{
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);
	Rcc_Enable(RCC_SYSCFG);

	// set 0-7 as output from port A for seven segment
	Gpio_ConfigPin(GPIO_A, 0, GPIO_OUTPUT, GPIO_PUSH_PULL);
	Gpio_ConfigPin(GPIO_A, 1, GPIO_OUTPUT, GPIO_PUSH_PULL);
	Gpio_ConfigPin(GPIO_A, 2, GPIO_OUTPUT, GPIO_PUSH_PULL);
	Gpio_ConfigPin(GPIO_A, 3, GPIO_OUTPUT, GPIO_PUSH_PULL);
	Gpio_ConfigPin(GPIO_A, 4, GPIO_OUTPUT, GPIO_PUSH_PULL);
	Gpio_ConfigPin(GPIO_A, 5, GPIO_OUTPUT, GPIO_PUSH_PULL);
	Gpio_ConfigPin(GPIO_A, 6, GPIO_OUTPUT, GPIO_PUSH_PULL);

	// configer push buttons pins
	Gpio_ConfigPin(GPIO_B, 4, GPIO_INPUT, GPIO_PULL_UP); // sit pin  as input
	Gpio_ConfigPin(GPIO_A, 9, GPIO_INPUT, GPIO_PULL_UP); // sit pin  as input

	Exti_Init(GPIO_A, 9, FALLING_EDGE);
	Exti_Init(GPIO_B, 4, FALLING_EDGE);

	// Enable Exti 0 and Exti4
	Exti_Enable(9);
	Exti_Enable(4);

	while (1)
	{

		switch (counter)
		{
		case 0:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, HIGH);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, LOW);

			break;
		case 1:
			Gpio_WritePin(GPIO_A, 0, LOW);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, LOW);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, LOW);
			Gpio_WritePin(GPIO_A, 6, LOW);
			break;
		case 2:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, LOW);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, HIGH);
			Gpio_WritePin(GPIO_A, 5, LOW);
			Gpio_WritePin(GPIO_A, 6, HIGH);
			break;
		case 3:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, LOW);
			Gpio_WritePin(GPIO_A, 6, HIGH);
			break;
		case 4:
			Gpio_WritePin(GPIO_A, 0, LOW);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, LOW);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);
			break;
		case 5:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, LOW);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);

			break;

		case 6:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, LOW);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, HIGH);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);
			break;
		case 7:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, LOW);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, LOW);
			Gpio_WritePin(GPIO_A, 6, LOW);
			break;

		case 8:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, HIGH);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);
			break;
		case 9:
			Gpio_WritePin(GPIO_A, 0, HIGH);
			Gpio_WritePin(GPIO_A, 1, HIGH);
			Gpio_WritePin(GPIO_A, 2, HIGH);
			Gpio_WritePin(GPIO_A, 3, HIGH);
			Gpio_WritePin(GPIO_A, 4, LOW);
			Gpio_WritePin(GPIO_A, 5, HIGH);
			Gpio_WritePin(GPIO_A, 6, HIGH);
			break;

		default:
			break;
		}

		uint32 i;
		for (i = 0; i < 1000000; i++)
			;
	}

	return 0;
}

void EXTI4_IRQHandler(void)
{

	if (counter == 9)
	{

		counter = 0;
	}

	else
	{
		counter += 1;
	}

	// clear pending flag
	SET_BIT(EXTI->PR, 4);
}

void EXTI9_5_IRQHandler(void)
{

	if (counter == 0)
	{
		counter = 9;
	}

	else
	{
		counter -= 1;
	}

	// clear pending flag
	SET_BIT(EXTI->PR, 9);
}
