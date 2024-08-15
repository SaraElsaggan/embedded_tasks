#include "Keypad.h"
#include "Gpio.h"
#include "Std_Types.h"

uint8 pressed_key; 
/*  اول حاجة بنعرف جلوبال فاريبل اسمه البرسد كيى اللى هحط الرقم اللى انا دست عليه
*/

uint8 keypad_button_array[4][3] = {
    /*
    دى بقى تو دى ارراى بشيل فيها كل زراير وارقام
     الكى باد بتاعتى عشان منها ه ريتريف ال قمية الزرار اللى دست عليه
    */
    // here are the button numbers as a 2d array
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {0, 0, 0},
};

uint8 pre_key_state[4][3] = {0}; // Matrix to store previous key states
/*
هنا بقى تو دى ارراى المفروض انها تشيل البريفوس ستيت بتاعت الزرار سواء كان متداس او لا هنفهم دروها قدام ف الكود
*/

void Keypad_Init(void)
{
    /*
   هنا بقى بنعمل انشايلز لل كي باد بتاعتنا حيث اننا
    بنخلى ال صفوف بتاعتها تكون اوتبوت وال الكومز 
    تكون انبوت عشان لما نيجى نلوب عليها 
    */
    uint8 index = 0;

    for (index = ROW_START_INDEX; index <= ROW_END_INDEX; index++)
    {
        /*
        الوفر لوب دى تبلوب ع الصفوف كلها تخليها اوتبوت
        */
        Gpio_ConfigPin(ROW_PORT, index, GPIO_OUTPUT, GPIO_PUSH_PULL);
        Gpio_WritePin(ROW_PORT, index, HIGH);
    }

    for (index = COL_START_INDEX; index <= COL_END_INDEX; index++)
    {
        /*
        ودى عشان تخلى الكولمز تكون انبوت
        */
        Gpio_ConfigPin(COL_PORT, index, GPIO_INPUT, GPIO_PULL_UP);
    }
}

void Keypad_Manage(void)
{
    uint8 row_index; // 
    uint8 col_index;
    uint8 col_read; // put the initlization with defentaion down
    uint8 col_read_pre;

    for (row_index = ROW_START_INDEX; row_index <= ROW_END_INDEX; row_index++)
    {
        Gpio_WritePin(ROW_PORT, row_index, LOW);
        for (col_index = COL_START_INDEX; col_index <= COL_END_INDEX; col_index++)
        {
            col_read_pre = Gpio_ReadPin(COL_PORT, col_index);
            for (unsigned long i = 0; i < 3000; i++){ /*handle debouncing*/}
            col_read = Gpio_ReadPin(COL_PORT, col_index);

            if (col_read_pre == col_read && pre_key_state[row_index][col_index] && col_read)
            {
                pressed_key = keypad_button_array[row_index - ROW_START_INDEX][col_index - COL_START_INDEX];
                KeypadCallout_KeyPressNotification();
            }
            pre_key_state[row_index][col_index] = !col_read; 
        }
        Gpio_WritePin(ROW_PORT, row_index, HIGH);
    }
}

uint8 Keypad_GetKey(void)
{
    /*
    return the pressed key value
    */
    return pressed_key;
}