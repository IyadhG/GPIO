#include"gpio.h"

//activation du clock
void GPIO_ClockEnable(unsigned int* gpio_x)
{
   __assert_param(IS_ALL_INSTANCE(gpio_x));
   
   *RCC_AHB1ENR |= (1 << (gpio_x - GPIO_A)/0x100);
  
}

//reset
void GPIO_DeInit(unsigned int* gpio_x)
{
  __assert_param(IS_ALL_INSTANCE(gpio_x));
  
  *RCC_AHB1RSTR |= (1 << (gpio_x - GPIO_A)/0x100);
  *RCC_AHB1RSTR &= ~(1 << (gpio_x - GPIO_A)/0x100);
       
}

//Configuration des differents GPIOx
void GPIO_Init(unsigned int* gpio_x, char Mode, char typeOutput, short int pin)
{
  if(Mode==INPUT) 
 {
   *(gpio_x + MODER) &= ~(3<<(pin*2));
 }
  if (Mode== OUTPUT)
 {
  *(gpio_x + MODER) |= 1<<(pin*2);
  *(gpio_x + MODER) &= ~(1<<((pin*2)+1));
            if (typeOutput == PP)
      {
          *(gpio_x + (OTYPER/4)) &= ~(1<<pin);
       }
            if (typeOutput == OD)
        {
            *(gpio_x + (OTYPER/4)) |= (1<<pin);
        }
 }
 if (Mode ==AF)
 {
 *(gpio_x + MODER) &= ~(1<<(pin*2));
 *(gpio_x + MODER) |= 1<<((pin*2)+1);
 }
 if (Mode ==AN)
 {
 *(gpio_x + MODER) |= 3<<(pin*2);

 }

}

//Lire la valeur dune seule PIN
unsigned char GPIO_ReadInputDataBit(unsigned int* gpio_x, unsigned short int GPIO_Pin)
{
  return(*(gpio_x + (IDR/4)) == (1<<GPIO_Pin)); 
}

//Lire la valeur du Port
unsigned short int GPIO_ReadInputData(unsigned int* gpio_x)
{
  return (*(gpio_x + (IDR/4)) ); 
}

//Mettre la valeur 1 ou 0 dans une seul PIN
void GPIO_WriteBit(unsigned int* gpio_x, unsigned short int GPIO_Pin, char BitVal)
{
  if (BitVal == Bit_SET)
  {*(gpio_x + (ODR/4)) |= BitVal << GPIO_Pin ;}
  else
  {*(gpio_x + (ODR/4)) &= ~(1 << GPIO_Pin);}
}

//Mettre une valeur désirée dans un Port complet
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal)
{
  *(gpio_x + (ODR/4)) = PortVal ;
}

