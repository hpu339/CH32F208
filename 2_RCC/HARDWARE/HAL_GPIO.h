#ifndef HAL_GPIO_H
#define HAL_GPIO_H


//宏函数定义
#define HAL_SET_GPIOA0()      (GPIOA->OUTDR |= GPIO_Pin_0)
#define HAL_RES_GPIOA0()      (GPIOA->OUTDR &= ~GPIO_Pin_0)
#define HAL_TOG_GPIOA0()      (GPIOA->OUTDR ^= GPIO_Pin_0)

void HAL_GPIO_MCOInit(uint8_t RCC_MCO);
void HAL_GPIOA0_Init();


#endif // !HAL_GPIO_H
