/*
 * @Author: Lixin Yang 15513924345@163.com
 * @Date: 2024-01-26 21:01:17
 * @LastEditors: Lixin Yang 15513924345@163.com
 * @LastEditTime: 2024-01-28 20:50:14
 * @FilePath: \EIDEe:\CH32F208WBU6\2_RCC\HARDWARE\HAL_TIMER.c
 * @Description: 封装项目中需要用到的TIM相关的函数
 */
#include "ch32f20x_conf.h"
#include "HAL_TIMER.h"

/**
 * @brief: 定时器2初始化配置
 * @param {uint16_t} PSC：预分频系数
 * @param {uint16_t} ARR：自动重装载的值
 * @return {*}
 */
void HAL_TIMER2_Init(uint16_t PSC, uint16_t ARR)
{
    RCC->APB1PCENR |= RCC_APB1Periph_TIM2;      //使能Timer2时钟

    TIM2->PSC = PSC - 1;        //预分频系数
    TIM2->ATRLR = ARR;          //自动重装载 

    TIM2->CTLR1 |= RELOAD_ENABLE;       //自动重加载使能
    TIM2->CTLR1 |= CMS_MODE0;           //边沿对齐模式
    TIM2->CTLR1 |= DIR_DOWN;            //向下减少
    TIM2->CTLR1 |= CNT_ENABLE;          //计数器使能
    TIM2->DMAINTENR |= TIM_IT_Update;   //使能更新中断

    TIM2->SWEVGR |= 0x0001;     //初始化计数器
}
