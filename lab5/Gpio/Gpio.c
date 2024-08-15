
#include "Gpio.h"
#include "Bit_operations.h"
#include "Gpio_Private.h"
#include "Utils.h"

void Gpio_ConfigPin(uint8 PortName, uint8 PinNum, uint8 PinMode, uint8 DefaultState)
{
	switch (PortName)
	{
	case GPIO_A:
		GPIOA_MODER &= ~(0x03 << (PinNum * 2));
		GPIOA_MODER |= (PinMode << (PinNum * 2));
		if (PinMode == GPIO_OUTPUT)
		{
			GPIOA_OTYPER &= ~(0x01 << PinNum);
			GPIOA_OTYPER |= (DefaultState << PinNum);
		}
		else if (PinMode == GPIO_INPUT)
		{
			GPIOA_PUPDR &= ~(0x03 << PinNum);
			GPIOA_PUPDR |= (DefaultState << PinNum);
		}

		break;
	case GPIO_B:

		GPIOB_MODER &= ~(0x03 << (PinNum * 2));
		GPIOB_MODER |= (PinMode << (PinNum * 2));
		if (PinMode == GPIO_OUTPUT)
		{

			GPIOB_OTYPER &= ~(0x03 << PinNum);
			GPIOB_OTYPER |= (DefaultState << PinNum);
		}
		else if (PinMode == GPIO_INPUT)
		{

			GPIOB_PUPDR &= ~(0x01 << PinNum);
			GPIOB_PUPDR |= (DefaultState << PinNum);
		}

		break;

	case GPIO_C:

		GPIOC_MODER &= ~(0x03 << (PinNum * 2));
		GPIOC_MODER |= (PinMode << (PinNum * 2));
		if (PinMode == GPIO_OUTPUT)
		{

			GPIOC_OTYPER &= ~(0x03 << PinNum);
			GPIOC_OTYPER |= (DefaultState << PinNum);
		}
		else if (PinMode == GPIO_INPUT)
		{

			GPIOC_PUPDR &= ~(0x01 << PinNum);
			GPIOC_PUPDR |= (DefaultState << PinNum);
		}

		break;

	case GPIO_D:

		GPIOD_MODER &= ~(0x03 << (PinNum * 2));
		GPIOD_MODER |= (PinMode << (PinNum * 2));
		if (PinMode == GPIO_OUTPUT)
		{

			GPIOD_OTYPER &= ~(0x03 << PinNum);
			GPIOD_OTYPER |= (DefaultState << PinNum);
		}
		else if (PinMode == GPIO_INPUT)
		{

			GPIOD_PUPDR &= ~(0x01 << PinNum);
			GPIOD_PUPDR |= (DefaultState << PinNum);
		}

		break;

	case GPIO_E:

		GPIOE_MODER &= ~(0x03 << (PinNum * 2));
		GPIOE_MODER |= (PinMode << (PinNum * 2));
		if (PinMode == GPIO_OUTPUT)
		{

			GPIOE_OTYPER &= ~(0x03 << PinNum);
			GPIOE_OTYPER |= (DefaultState << PinNum);
		}
		else if (PinMode == GPIO_INPUT)
		{

			GPIOE_PUPDR &= ~(0x01 << PinNum);
			GPIOE_PUPDR |= (DefaultState << PinNum);
		}

		break;


	default:
		break;
	}
}

void Gpio_WritePin(uint8 PortName, uint8 PinNum, uint8 Data)
{
	// check if the pin is output
	uint8 check;
	switch (PortName)
	{
	case GPIO_A:
		check = (GPIOA_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
		if (check == 0x01)
		{
			GPIOA_ODR &= ~(0x1 << PinNum);
			GPIOA_ODR |= (Data << PinNum);
		}
		break;
	case GPIO_B:
		check = (GPIOB_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
		if (check == 0x01)
		{
			GPIOB_ODR &= ~(0x1 << PinNum);
			GPIOB_ODR |= (Data << PinNum);
		}
		break;

	case GPIO_C:
		check = (GPIOC_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
		if (check == 0x01)
		{
			GPIOC_ODR &= ~(0x1 << PinNum);
			GPIOC_ODR |= (Data << PinNum);
		}
		break;

	case GPIO_D:
		check = (GPIOD_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
		if (check == 0x01)
		{
			GPIOD_ODR &= ~(0x1 << PinNum);
			GPIOD_ODR |= (Data << PinNum);
		}
		break;

	case GPIO_E:
		check = (GPIOE_MODER & (0x3 << (2 * PinNum))) >> (2 * PinNum);
		if (check == 0x01)
		{
			GPIOE_ODR &= ~(0x1 << PinNum);
			GPIOE_ODR |= (Data << PinNum);
		}
		break;

	default:
		break;
	}
}

uint8 Gpio_ReadPin(uint8 PortName, uint8 PinNum)
{
	uint8 ReadPin ;
	switch (PortName)
	{
	case GPIO_A:
		ReadPin = READ_BIT(GPIOA_IDR, PinNum);
		break;
	case GPIO_B:
		ReadPin = READ_BIT(GPIOB_IDR, PinNum);
		break;
	case GPIO_C:
		ReadPin = READ_BIT(GPIOC_IDR, PinNum);
		break;
	case GPIO_D:
		ReadPin = READ_BIT(GPIOD_IDR, PinNum);
		break;
	case GPIO_E:
		ReadPin = READ_BIT(GPIOE_IDR, PinNum);
		break;
	
	default:
		break;
	}
	return ReadPin;
}