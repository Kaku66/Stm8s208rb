/* vzorov� projekt (sem pi�te stru�n� popis projektu)

*/

#include "stm8s.h"
#include "milis.h"

#define LED5H GPIO_WriteHigh(GPIOC,GPIO_PIN_5);
#define LED5L GPIO_WriteLow(GPIOC,GPIO_PIN_5);

#define pushpull GPIO_Init(GPIOC,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_SLOW);
#define tlacitko GPIO_Init(GPIOE, GPIO_PIN_4,GPIO_MODE_IN_FL_NO_IT);

uint8_t x = 0;


void main(void){
CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // 16MHz z intern�ho RC oscil�toru
pushpull; // nastav�me PC5 jako v�stup typu push-pull (LEDka)
tlacitko; // nastav�me PE4 jako vstup (tla��tko)

init_milis(); 

  while (1){
	if(GPIO_ReadInputPin(GPIOE,GPIO_PIN_4)==RESET){ // kontrolujeme zda je tla��tko stisknut�... (je na PE4 log.0)
	for(x=0;x<5;x++){
		delay_ms(1000);
		LED5H; // pokud ano tak rozsv�c�me LED  (zapisujeme log.1)
		delay_ms(1000);
		LED5L; // pokud ne tak zhasneme LED  (zapisujeme log.0)s
}
 }
}
}


// pod t�mto koment��em nic nem��te 
#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
