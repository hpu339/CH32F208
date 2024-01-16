/*
 * @Author: Lixin Yang 15513924345@163.com
 * @Date: 2023-12-04 22:54:17
 * @LastEditors: Lixin Yang 15513924345@163.com
 * @LastEditTime: 2024-01-14 22:08:35
 * @FilePath: \EIDEe:\CH32F208WBU6\2_RCC\HARDWARE\HAL_GPIO.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "ch32f20x_conf.h"

/**
 * @brief: MCO引脚初始化函数
 * @param {uint8_t} RCC_MCO
 * @return {*}
 */
void HAL_GPIO__MCOInit(uint8_t RCC_MCO)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    RCC_MCOConfig(RCC_MCO);
}
