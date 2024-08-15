#include "Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"
#include "Keypad.h"
int main()
{
	Rcc_Init();
	Rcc_Enable(RCC_GPIOA);
	Rcc_Enable(RCC_GPIOB);

	Keypad_Init();

	uint32 i = 0;
	for (i = 0; i < 7; i++)
	{ // configer the 7 segment dispaly as push pull output
		Gpio_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	}

	while (1)
	{
		Keypad_Manage();
		for (unsigned long i = 0; i < 10000; i++)
		{ /*Delay loop*/
		}
	}

	return 0;
}

void KeypadCallout_KeyPressNotification(void)
{

	// application depenedent
	int key = Keypad_GetKey();
	switch (key)
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
		Gpio_WritePin(GPIO_A, 3, LOW);
		Gpio_WritePin(GPIO_A, 4, LOW);
		Gpio_WritePin(GPIO_A, 5, HIGH);
		Gpio_WritePin(GPIO_A, 6, HIGH);
		break;

	default:
		break;
	}
}
