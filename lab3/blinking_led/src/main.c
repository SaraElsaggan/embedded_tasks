// Sara Mahmoud Elsaggan     SECTION 1      BN:28
// Fatma Ehab                SECTION 1      BN:41

#define GPIOB_BASE_ADDR 0x40020400								   // this is the base addres of the gpio
#define GPIOB_MODER   (*(unsigned long *)(GPIOB_BASE_ADDR + 0x00)) // mode regestor to spscfiy the mode of the pin
#define GPIOB_OTYPER  (*(unsigned long *)(GPIOB_BASE_ADDR + 0x04)) //output type to chose push_pull or open drain
#define GPIOB_ODR     (*(unsigned long *)(GPIOB_BASE_ADDR + 0x14)) //to read the content of the pin
#define RCC_AHB1ENR   (*(unsigned long *)(0x40023800 + 0x30))




int main()
{
	RCC_AHB1ENR |= (1 << 1);// Enable clock to fpr port B

	unsigned char mode_pin_gpio_b = 1; // pin 3 output mode

	GPIOB_MODER &= ~(0x03 << 3 * 2);   // clear bin 3
	GPIOB_MODER |= mode_pin_gpio_b << (3 * 2); // set this pin to be in output mode

	GPIOB_OTYPER &= ~(1 << 3); //output type to be push pull

	GPIOB_ODR |= (1 << 3);
	while(1){
		        // Toggle PA5
	   GPIOB_ODR |= (1 << 3);
	   for (volatile unsigned long i = 0; i < 1000000; i++) {
            // Delay loop
        }

        // Toggle PB2 low
        GPIOB_ODR &= ~(1 << 3);
        // Delay
        for (volatile unsigned long i = 0; i < 1000000; i++) {
            // Delay loop
        }
	}
	return 0;
}
