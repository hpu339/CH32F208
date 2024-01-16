/*
 * @Author: Lixin Yang 15513924345@163.com
 * @Date: 2023-11-04 10:35:10
 * @LastEditors: Lixin Yang 15513924345@163.com
 * @LastEditTime: 2024-01-16 22:50:56
 * @FilePath: \EIDEe:\CH32F208WBU6\1_RCC\USER\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "debug.h"
#include "ch32f20x_conf.h"
#include "HAL_GPIO.h"

uint8_t cnt = 0;

int main(void)
{
    //HAL_GPIO__MCOInit(RCC_MCO_HSI);
    //uint8_t cnt = 0;

    
    RCC->APB2PCENR |= (1<<2);
    GPIOA->CFGLR &= ~(0x000000ff<<(4*0));
    GPIOA->CFGLR |= ((3<<(4*0)) | (8<<(4*1)));
    GPIOA->OUTDR &= ~(1<<0);
    GPIOA->OUTDR |= (1<<1);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);


    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);    //开启tim2定时器

    TIM_TimeBaseInitTypeDef TimeBaseInitStructure;

    TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Down;
    TimeBaseInitStructure.TIM_Period = 10000;     //10ms
    TimeBaseInitStructure.TIM_Prescaler = 143;     //144M / (71+1)   1M
    TIM_TimeBaseInit(TIM2, &TimeBaseInitStructure);
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM2,ENABLE);
	GPIOA->OUTDR |= (1<<0);     //GPIOA->PORT0 输出1
    while(1)
    {
        if(cnt == 100)
        {
            cnt = 0;
            // GPIOA->OUTDR |= (1<<0);     //GPIOA->PORT0 输出1
            GPIOA->OUTDR = ~(GPIOA->OUTDR);
        }
    }
 
  
    
}
void TIM2_IRQHandler(void)
{
    
    if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET)
    {
        cnt++;
        TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
    }
}
