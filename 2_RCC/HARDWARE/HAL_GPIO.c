/*
 * @Author: Lixin Yang 15513924345@163.com
 * @Date: 2023-12-04 22:54:17
 * @LastEditors: Lixin Yang 15513924345@163.com
 * @LastEditTime: 2024-01-14 22:08:35
 * @FilePath: \EIDEe:\CH32F208WBU6\2_RCC\HARDWARE\HAL_GPIO.c
 * @Description: 存放与GPIO相关的函数
 */
#include "ch32f20x_conf.h"
#include "HAL_GPIO.h"
/**
 * @brief: MCO引脚初始化函数
 * @param {uint8_t} RCC_MCO
 * @return {*}
 */
void HAL_GPIO_MCOInit(uint8_t RCC_MCO)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    RCC_MCOConfig(RCC_MCO);
}
/**
 * @brief: PA0引脚初始化函数
 * @return {*}
 */
void HAL_GPIOA0_Init(void)
{
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOA;         //使能GPIOA时钟
    GPIOA->CFGLR &= ~(0x000000ff<<(4*0));
    GPIOA->CFGLR |= (3<<(4*0)) ;                    //PA0 50Mhz 推挽输出
    GPIOA->OUTDR &= ~(1<<0);                        //PA0 拉低其余拉高
    GPIOA->OUTDR |= (1<<0);                         //PA0 拉高
}