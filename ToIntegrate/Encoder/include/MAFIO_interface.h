#ifndef _MAFIO_INTERFACE_H_
#define _MAFIO_INTERFACE_H_

#define MAFIO_GPIOA     0
#define MAFIO_GPIOB     1
#define MAFIO_GPIOC     2

#define MAFIO_EXTI0      0
#define MAFIO_EXTI1      1
#define MAFIO_EXTI2      2
#define MAFIO_EXTI3      3
#define MAFIO_EXTI4      4
#define MAFIO_EXTI5      5
#define MAFIO_EXTI6      6
#define MAFIO_EXTI7      7
#define MAFIO_EXTI8      8
#define MAFIO_EXTI9      9
#define MAFIO_EXTI10     10
#define MAFIO_EXTI11     11
#define MAFIO_EXTI12     12
#define MAFIO_EXTI13     13
#define MAFIO_EXTI14     14
#define MAFIO_EXTI15     15

void MAFIO_voidInit( void );
void MAFIO_voidExternalInterruptRemap( u8 Copy_u8Line , u8 Copy_u8PortMap );

#endif