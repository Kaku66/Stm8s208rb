/* vzorov� projekt (sem pi�te stru�n� popis projektu)

*/

#include "stm8s.h"
#include "milis.h"

uint16_t x;

uint8_t minuly_stav=1; // zde si budeme ukl�dat minul� stav tla��tka (1=tla��tko stisknut�, 0=tla��tko uvoln�n�)
uint8_t aktualni_stav=1;

uint8_t minuly_stav2=1; // zde si budeme ukl�dat minul� stav tla��tka (1=tla��tko stisknut�, 0=tla��tko uvoln�n�)
uint8_t aktualni_stav2=1;

void main(void){
CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // 16MHz z intern�ho RC oscil�toru
init_milis();
GPIO_Init(GPIOB, GPIO_PIN_ALL, GPIO_MODE_OUT_PP_LOW_SLOW);
GPIO_Init(GPIOD, GPIO_PIN_5, GPIO_MODE_IN_FL_NO_IT);
GPIO_Init(GPIOD, GPIO_PIN_6, GPIO_MODE_IN_FL_NO_IT);

  while (1){
    if(GPIO_ReadInputPin(GPIOD,GPIO_PIN_5)==RESET){ // zjisti jestli je tla��tko stisknut�
   aktualni_stav=1; // pokud ano ulo� �e je stisknut�
  }
  else{
   aktualni_stav=0;// jinak ulo� �e je uvoln�n�
  }

 // te� budeme kontrolovat jestli nenastal "okam�ik stisku" nebo "okam�ik uvoln�n�"

  if(minuly_stav==1 && aktualni_stav==0){ // je to okam�ik stisku ?
   x++; // pokud ano rozsv�t�me LEDku
  }

  minuly_stav = aktualni_stav;

     if(GPIO_ReadInputPin(GPIOD,GPIO_PIN_6)==RESET){ // zjisti jestli je tla��tko stisknut�
   aktualni_stav2=1; // pokud ano ulo� �e je stisknut�
  }
  else{
   aktualni_stav2=0;// jinak ulo� �e je uvoln�n�
  }



  if(minuly_stav2==1 && aktualni_stav2==0){ // je to okam�ik stisku ?
   x--; // pokud ano rozsv�t�me LEDku
  }

  minuly_stav2 = aktualni_stav2;
	
	if(GPIO_ReadInputPin(GPIOD,GPIO_PIN_5)==RESET){ // zjisti jestli je tla��tko stisknut�
   aktualni_stav2=1; // pokud ano ulo� �e je stisknut�
  }

    GPIO_Write(GPIOB, x);
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
