// Sara Mahmoud Elsaggan     SECTION 1      BN:28
// Fatma Ehab                SECTION 1      BN:41
#include "Gpio/Gpio.h"
#include "Rcc.h"
#include "Std_Types.h"

int main()
{

	Rcc_Init();
	Rcc_Enable(RCC_GPIOB);

	Gpio_ConfigPin(GPIO_B, 3, GPIO_INPUT, GPIO_PULL_UP);

	uint32 i;
	for (i = 5; i < 8; i++)
	{
		Gpio_ConfigPin(GPIO_B, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	}

	uint8 counter = 0;
	uint8 button_state = 0; // indecates wheater the button is pressed or released

	while (1)
	{
		uint8 input = Gpio_ReadPin(GPIO_B, 3);

		for (volatile unsigned long i = 0; i < 80000; i++)
		{
		} // for loop to handle the debouncing of the push button

		if ((!input) && (button_state == 0))
		{
			button_state = 1; // set the state of the button to be pressed

			// switch cases to change the led color with each press on the button
			switch (counter)
			{
			case 0:
				counter = 1;
				// set all pins (white)
				Gpio_WritePin(GPIO_B, 5, 1);
				Gpio_WritePin(GPIO_B, 6, 1);
				Gpio_WritePin(GPIO_B, 7, 1);
				break;

			case 1:
				counter = 2;
				// set pins 5 and 6 (red + green)
				Gpio_WritePin(GPIO_B, 5, 1);
				Gpio_WritePin(GPIO_B, 6, 1);
				Gpio_WritePin(GPIO_B, 7, 0);
				break;

			case 2:
				counter = 3;
				// set pins 5 (red )
				Gpio_WritePin(GPIO_B, 5, 1);
				Gpio_WritePin(GPIO_B, 6, 0);
				Gpio_WritePin(GPIO_B, 7, 0);
				break;

			case 3:
				counter = 4;
				// reset all pins (black)
				Gpio_WritePin(GPIO_B, 5, 0);
				Gpio_WritePin(GPIO_B, 6, 0);
				Gpio_WritePin(GPIO_B, 7, 0);
				break;

			case 4:
				counter = 5;
				// set pin 7 ( blue )
				Gpio_WritePin(GPIO_B, 5, 0);
				Gpio_WritePin(GPIO_B, 6, 0);
				Gpio_WritePin(GPIO_B, 7, 1);
				break;

			case 5:
				counter = 6;
				// set pin 6 , 7 (green + blue)
				Gpio_WritePin(GPIO_B, 5, 0);
				Gpio_WritePin(GPIO_B, 6, 1);
				Gpio_WritePin(GPIO_B, 7, 1);
				break;

			case 6:
				counter = 7;
				// set pins 5 , 7 (red + blue)
				Gpio_WritePin(GPIO_B, 5, 1);
				Gpio_WritePin(GPIO_B, 6, 0);
				Gpio_WritePin(GPIO_B, 7, 1);
				break;

			case 7:
				counter = 0;
				// set pin 6(green)
				Gpio_WritePin(GPIO_B, 5, 0);
				Gpio_WritePin(GPIO_B, 6, 1);
				Gpio_WritePin(GPIO_B, 7, 0);
				break;
			default:
				break;
			}
		}

		if (input) // now it the buttun is not clicked make the button state to be relased
		{
			button_state = 0; // button state to be relased
		}
	}

	return 0;
}
