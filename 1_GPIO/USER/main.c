/*
 * @Author: Lixin Yang
 * @Date: 2023-10-08 23:26:26
 * @LastEditTime: 2023-11-03 23:54:01
 * @FilePath: \.cmsise:\CH32F208WBU6\CH32F208\Project_template\USER\main.c
 * @Description: GPIO点灯，寄存器地址开发，寄存器开发，库函数开发
 * 
 */


//#include "ch32f20x.h"
#include "debug.h"
#include "ch32f20x_conf.h"
//#include "stdio.h"	


int main( void )
{
    
    // /*  寄存器地址开发  */
    // uint8_t KeyValue;
    // *(uint32_t *)(0x40021018) |= (1<<2);     //RCC->APB2->portA使能
	// *(uint32_t *)(0x40010800) &= ~(0x000000ff<<(4*0));	//低八位全清零
    // *(uint32_t *)(0x40010800) |= (3<<(4*0));     //GPIOA->PORT0->输出模式，50Mhz 其他端口为输入模式
    // *(uint32_t *)(0x40010800) |= (8<<(4*1));    //GPIOA->PORT1->输入模式 上下拉
	
    // *(uint32_t *)(0x4001080c) &= ~(1<<0);     //GPIOA->PORT0 输出0
    // *(uint32_t *)(0x4001080c) |= (1<<1);        //GPIOA->PORT1->上拉

    // while(1)
    // {
    //     KeyValue = (((*(uint32_t *)(0x40010808))>>1) & 0x00000001);
    //     if(KeyValue == 1) 
    //     {    
    //         *(uint32_t *)(0x4001080c) |= (1<<0);     //GPIOA->PORT0 输出1
    //     }
    //     else
    //     { 
    //         *(uint32_t *)(0x4001080c) &= ~(1<<0);   
    //     }
    // }
    
    /* 寄存器开发 */
    uint8_t KeyValue;
    RCC->APB2PCENR |= (1<<2);
    GPIOA->CFGLR &= ~(0x000000ff<<(4*0));
    GPIOA->CFGLR |= ((3<<(4*0)) | (8<<(4*1)));
    GPIOA->OUTDR &= ~(1<<0);
    GPIOA->OUTDR |= (1<<1);

    while(1)
    {
        KeyValue = ((GPIOA->INDR>>1) & 1);
        if(KeyValue == 1) 
        {    
            GPIOA->OUTDR |= (1<<0);     //GPIOA->PORT0 输出1
        }
        else
        { 
            GPIOA->OUTDR &= ~(1<<0);   
        }
    }
    
    /* 库函数开发 */
    // RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   
    // GPIO_InitTypeDef GPIO_InitStructure1;
    // GPIO_InitTypeDef GPIO_InitStructure2;

    // GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_Out_PP;
    // GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_0;
    // GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;

    // GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_IPU;
    // GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_1;
    // GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_50MHz;

    // GPIO_Init(GPIOA, &GPIO_InitStructure1);
    // GPIO_Init(GPIOA, &GPIO_InitStructure2);

    // while( 1 )
    // {
    //     GPIO_WriteBit(GPIOA,GPIO_Pin_0,GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1));
    // }
}


