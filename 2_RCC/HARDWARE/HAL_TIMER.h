/*
 * @Author: Lixin Yang 15513924345@163.com
 * @Date: 2024-01-26 21:02:27
 * @LastEditors: Lixin Yang 15513924345@163.com
 * @LastEditTime: 2024-01-28 20:29:06
 * @FilePath: \EIDEe:\CH32F208WBU6\2_RCC\HARDWARE\HAL_TIMER.h
 * @Description: 声明TIMR.c中的函数并且定义相关的寄存器操作数值
 */
#ifndef HAL_TIMER_H
#define HAL_TIMER_H

/* TIMx_CTLR1寄存器*/
//自动重装载使能位
#define RELOAD_ENABLE    (uint16_t)(0x0080)
#define RELOAD_DISABLE   (uint16_t)(0x0000)
//中央对齐陌生选择
#define CMS_MODE0        (uint16_t)(0x0000)
#define CMS_MODE1        (uint16_t)(0x0020)
#define CMS_MODE2        (uint16_t)(0x0040)
#define CMS_MODE3        (uint16_t)(0x0060)
//计数器方向
#define DIR_UP           (uint16_t)(0x0000)
#define DIR_DOWN         (uint16_t)(0x0010)
//计数器使能
#define CNT_ENABLE       (uint16_t)(0x0001)
#define CNT_DISABLE      (uint16_t)(0x0000)


  

void HAL_TIMER2_Init(uint16_t PSC, uint16_t ARR);


#endif // !HAL_TIMER_H

