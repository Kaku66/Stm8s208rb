/* vzorový projekt (sem pište struèný popis projektu)

*/

#include "stm8s.h"
#include "milis.h"

uint8_t minuly_stav=0; // zde si budeme ukládat minulý stav tlaèítka (1=tlaèítko stisknuté, 0=tlaèítko uvolnìné)
uint8_t aktualni_stav=0;  // zde si budeme ukládat aktuální stav tlaèítka (1=tlaèítko stisknuté, 0=tlaèítko uvolnìné)
uint8_t stav_ledky=0;

void main(void){
CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // 16MHz z interního RC oscilátoru
init_milis(); 
GPIO_Init(GPIOB,GPIO_PIN_0,GPIO_MODE_OUT_PP_LOW_SLOW);
GPIO_Init(GPIOB, GPIO_PIN_1,GPIO_MODE_IN_FL_NO_IT);

  while (1){
	// naèteme aktuální stav tlaèítka
  if(GPIO_ReadInputPin(GPIOB,GPIO_PIN_1)==RESET){ // zjisti jestli je tlaèítko stisknuté 
   aktualni_stav=1; // pokud ano ulož že je stisknuté
  } 
  else{
   aktualni_stav=0;// jinak ulož že je uvolnìné
  } 
 
  if(minuly_stav==0 && aktualni_stav==1){ // je to okamžik stisku ?
   // pøepneme stav LEDky
   if(stav_ledky==1){ // pokud je LEDka rozsvícená
    GPIO_WriteLow(GPIOB,GPIO_PIN_0); // zhasneme ji...
    stav_ledky=0; // ...a zapamatujeme si že je zhasnutá
   }else{ // jinak je LEDka zhasnutá, takže...
    GPIO_WriteHigh(GPIOB,GPIO_PIN_0); // ...ji rozsvítíme ...
    stav_ledky=1; // ... a zapamatujeme si že je rozsvícená
   }
  }
 
  minuly_stav = aktualni_stav;
	}
}



// pod tímto komentáøem nic nemìòte 
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
