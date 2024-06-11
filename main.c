/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "gpio.h"
#include <stdio.h>


/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 100
                                                       
/* Private function prototypes -----------------------------------------------*/
void Delay(volatile unsigned  int  nCount);

void OK(void)
{
  __asm("NOP");
}

void assert_failed(void)
{
  while(1){};
}

int main()
{
  
//Activer l'horloge pour le Port D
GPIO_ClockEnable(GPIO_D);

//Re-intialiser les registers de port D
GPIO_DeInit(GPIO_D);

//Configure PD8 et PD9 en mode Output Push pull
GPIO_Init(GPIO_D,OUTPUT,PP,Pin8);
GPIO_Init(GPIO_D,OUTPUT,PP,Pin9);


      GPIO_WriteBit(GPIO_D ,Pin8 ,Bit_SET);
      Delay(0xFFFFF);
      GPIO_WriteBit(GPIO_D ,Pin9 ,Bit_SET);
      Delay(0xFFFF);
    GPIO_WriteBit(GPIO_D ,Pin8 ,Bit_RESET);
    GPIO_WriteBit(GPIO_D ,Pin9 ,Bit_RESET);
    

GPIO_ReadInputDataBit(GPIO_D,Pin3);
GPIO_ReadInputData(GPIO_D);

GPIO_Write(GPIO_C,0xFFFF);

return 0;

}

void Delay(volatile unsigned  int  nCount)
{
  for(; nCount != 0; nCount--);
}