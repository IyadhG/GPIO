
//l'adresse du RCC ENABLE
#define RCC_AHB1ENR (unsigned short int*)(0x40023800+0x30)

//l'adresse du RCC RESET
#define RCC_AHB1RSTR (unsigned short int*)(0x40023800+0x10)

//Les adresses de bases de tous les GPIOx.
#define GPIO_A (unsigned int*)(0x40020000)
#define GPIO_B (unsigned int*)(0x40020400)
#define GPIO_C (unsigned int*)(0x40020800)
#define GPIO_D (unsigned int*)(0x40020C00)
#define GPIO_E (unsigned int*)(0x40021000)
#define GPIO_F (unsigned int*)(0x40021400)
#define GPIO_G (unsigned int*)(0x40021800)
#define GPIO_H (unsigned int*)(0x40021C00)
#define GPIO_I (unsigned int*)(0x40022000)
#define GPIO_J (unsigned int*)(0x40022400)
#define GPIO_K (unsigned int*)(0x40022800)

//Les offset des differents registres
# define MODER   0x00
# define OTYPER  0x04
# define IDR     0x10
# define ODR     0x14

//Les differents modes de fonctionement
#define INPUT  0x0
#define OUTPUT 0x1
#define AF    0x2
#define AN    0x3

//Types de sortie
#define PP 0x00 
#define OD 0x01

#define Bit_RESET 0x0
#define Bit_SET 0x1

//GPIO Pin 
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7
#define Pin8 8
#define Pin9 9
#define Pin10 10
#define Pin11 11
#define Pin12 12
#define Pin13 13
#define Pin14 14
#define Pin15 15


#define __assert_param(expr)    ((expr) ? OK(): assert_failed())
#define IS_ALL_INSTANCE(INSTANCE) ((INSTANCE == GPIO_A) || \
                                   (INSTANCE == GPIO_B) || \
                                   (INSTANCE == GPIO_C) || \
                                   (INSTANCE == GPIO_D) || \
                                   (INSTANCE == GPIO_E) )
                                        
void GPIO_ClockEnable(unsigned int* gpio_x);
void GPIO_DeInit(unsigned int* gpio_x);
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin);
unsigned char GPIO_ReadInputDataBit(unsigned int* gpio_x, unsigned short int GPIO_Pin);
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x);
void GPIO_WriteBit(unsigned int* gpio_x, unsigned short int GPIO_Pin, char BitVal); 
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal);

