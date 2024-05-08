/* vzorov� projekt (sem pi�te stru�n� popis projektu)

*/

#include "stm8s.h"
#include "milis.h"

uint8_t minuly_stav=0; // zde si budeme ukl�dat minul� stav tla��tka (1=tla��tko stisknut�, 0=tla��tko uvoln�n�)
uint8_t aktualni_stav=0;  // zde si budeme ukl�dat aktu�ln� stav tla��tka (1=tla��tko stisknut�, 0=tla��tko uvoln�n�)
uint8_t stav_ledky=0;

void main(void){
CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // 16MHz z intern�ho RC oscil�toru
init_milis(); 
GPIO_Init(GPIOB,GPIO_PIN_0,GPIO_MODE_OUT_PP_LOW_SLOW);
GPIO_Init(GPIOB, GPIO_PIN_1,GPIO_MODE_IN_FL_NO_IT);

  while (1){
	// na�teme aktu�ln� stav tla��tka
  if(GPIO_ReadInputPin(GPIOB,GPIO_PIN_1)==RESET){ // zjisti jestli je tla��tko stisknut� 
   aktualni_stav=1; // pokud ano ulo� �e je stisknut�
  } 
  else{
   aktualni_stav=0;// jinak ulo� �e je uvoln�n�
  } 
 
  if(minuly_stav==0 && aktualni_stav==1){ // je to okam�ik stisku ?
   // p�epneme stav LEDky
   if(stav_ledky==1){ // pokud je LEDka rozsv�cen�
    GPIO_WriteLow(GPIOB,GPIO_PIN_0); // zhasneme ji...
    stav_ledky=0; // ...a zapamatujeme si �e je zhasnut�
   }else{ // jinak je LEDka zhasnut�, tak�e...
    GPIO_WriteHigh(GPIOB,GPIO_PIN_0); // ...ji rozsv�t�me ...
    stav_ledky=1; // ... a zapamatujeme si �e je rozsv�cen�
   }
  }
 
  minuly_stav = aktualni_stav;
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
