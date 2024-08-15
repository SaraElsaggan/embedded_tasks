// Sara Mahmoud Elsaggan     SECTION 1      BN:28
// Fatma Ehab                SECTION 1      BN:41

#define GPIOB_BASE_ADDR 0x40020400
#define GPIOB_MODER (*(unsigned long *)(GPIOB_BASE_ADDR + 0x00))
#define GPIOB_OTYPER (*(unsigned long *)(GPIOB_BASE_ADDR + 0x04))
#define GPIOB_INTYPER (*(unsigned long *)(GPIOB_BASE_ADDR + 0x0c))
#define GPIOB_INDATA (*(unsigned long *)(GPIOB_BASE_ADDR + 0x10))
#define GPIOB_ODR (*(unsigned long *)(GPIOB_BASE_ADDR + 0x14))
#define RCC_AHB1ENR (*(unsigned long *)(0x40023800 + 0x30))

int main(void)
{
    RCC_AHB1ENR |= (1 << 1); // Enable clock to fpr port B

    GPIOB_MODER &= ~(0x03 << (3 * 2));  // Clear mode bits for pin 3 (input mode)
    GPIOB_INTYPER |= (0x01 << (3 * 2)); // Set pull-up mode for pin 3

    // set pins 5 , 6 , 7 as output mode
    GPIOB_MODER |= 1 << (5 * 2);
    GPIOB_MODER |= 1 << (6 * 2);
    GPIOB_MODER |= 1 << (7 * 2);

    // set pins 5 , 6 , 7 as push pull type
    GPIOB_OTYPER &= ~(1 << 5);
    GPIOB_OTYPER &= ~(1 << 6);
    GPIOB_OTYPER &= ~(1 << 7);

    unsigned int count = 0;

    char button_state = 0; // indecates wheater the button is pressed or released

    while (1)
    {

        for (volatile unsigned long i = 0; i < 80000; i++){}  // for loop to handle the debouncing of the push button

        if ((!(GPIOB_INDATA & (1 << 3))) && (button_state == 0))  // check if the button is pressed and the button state is relasead
        {
            button_state = 1; // set the state of the button to be pressed

            // switch cases to change the led color with each press on the button
            switch (count)
            {
            case 0:
                count = 1; 
                // set all pins (white)
                GPIOB_ODR |= (1 << 5); // Pin 5
                GPIOB_ODR |= (1 << 6); // Pin 6
                GPIOB_ODR |= (1 << 7); // Pin 7
                break;
            case 1:
                // set pins 5 and 6 (red + green)
                count = 2;
                GPIOB_ODR |= (1 << 5);  // Pin 5
                GPIOB_ODR |= (1 << 6);  // Pin 6
                GPIOB_ODR &= ~(1 << 7); // Pin 7
                break;
            case 2:
                // set pins 5 (red )
                count = 3;
                GPIOB_ODR |= (1 << 5);  // Pin 5
                GPIOB_ODR &= ~(1 << 6); // Pin 6
                GPIOB_ODR &= ~(1 << 7); // Pin 7
                break;
            case 3:
                // reset all pins (black)
                count = 4;
                GPIOB_ODR &= ~(1 << 5); // Pin 5
                GPIOB_ODR &= ~(1 << 6); // Pin 6
                GPIOB_ODR &= ~(1 << 7); // Pin 7
                break;
            case 4:
                // set pin 7 ( blue )
                count = 5;
                GPIOB_ODR &= ~(1 << 5); // Pin 5
                GPIOB_ODR &= ~(1 << 6); // Pin 6
                GPIOB_ODR |= (1 << 7);  // Pin 7
                break;

            case 5:
                //set pin 6 , 7 (green + blue)
                count = 6;
                GPIOB_ODR &= ~(1 << 5); // Pin 5
                GPIOB_ODR |= (1 << 6);  // Pin 6
                GPIOB_ODR |= (1 << 7);  // Pin 7
                break;
            case 6:
                // set pins 5 , 7 (red + blue)
                count = 7;
                GPIOB_ODR |= (1 << 5);  // Pin 5
                GPIOB_ODR &= ~(1 << 6); // Pin 6
                GPIOB_ODR |= (1 << 7);  // Pin 7
                break;
            case 7:
                // set pin 6(green)
                count = 0;
                GPIOB_ODR &= ~(1 << 5); // Pin 5
                GPIOB_ODR |= (1 << 6);  // Pin 6
                GPIOB_ODR &= ~(1 << 7); // Pin 7
                break;
            
            }
        }

        if (((GPIOB_INDATA & (1 << 3)))) // now it the buttun is not clicked make the button state to be relased
        {
            button_state = 0;  //button state to be relased
        }
    }
}


