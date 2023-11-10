#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "font.h"
#include "sh1106.h"


int main()
{  
  stdio_init_all();

  i2c_init(i2c_default, 400 * 1000);
  gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
  gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
  gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
  gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    
  SH1106_Init();  // initialise

  SH1106_GotoXY (0,0);
  SH1106_Puts ("X", &Font_7x10, 1);

  SH1106_GotoXY (120,0);
  SH1106_Puts ("X", &Font_7x10, 1);

  SH1106_GotoXY (0,53);
  SH1106_Puts ("X", &Font_7x10, 1);

  SH1106_GotoXY (120,53);
  SH1106_Puts ("X", &Font_7x10, 1);

  SH1106_UpdateScreen(); //display

  while (1)
  {
    sleep_ms(200);
  }

  return 0;
}
//change to smaller font
