/*
 * @Author: Lixin Yang 15513924345@163.com
 * @Date: 2023-11-04 10:35:10
 * @LastEditors: Lixin Yang 15513924345@163.com
 * @LastEditTime: 2024-01-28 20:45:18
 * @FilePath: \EIDEe:\CH32F208WBU6\1_RCC\USER\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "debug.h"
#include "ch32f20x_conf.h"
#include "HAL_GPIO.h"
#include "HAL_TIMER.h"

uint8_t cnt = 0;

int main(void)
{

    HAL_GPIOA0_Init();
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    HAL_TIMER2_Init(144,10000);


    while(1)
    {
        if(cnt == 100)
        {
            cnt = 0;
            HAL_TOG_GPIOA0();
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
