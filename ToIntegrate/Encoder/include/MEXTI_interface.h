#ifndef _MEXTI_INTERFACE_H
#define _MEXTI_INTERFACE_H

#define MEXTI_FALLING_EDGE  0
#define MEXTI_RISING_EDGE   1
#define MEXTI_ON_CHANGE     2

#define MEXTI_LINE0    0
#define MEXTI_LINE1    1
#define MEXTI_LINE2    2
#define MEXTI_LINE3    3
#define MEXTI_LINE4    4
#define MEXTI_LINE5    5
#define MEXTI_LINE6    6
#define MEXTI_LINE7    7
#define MEXTI_LINE8    8
#define MEXTI_LINE9    9
#define MEXTI_LINE10   10
#define MEXTI_LINE11   11
#define MEXTI_LINE12   12
#define MEXTI_LINE13   13
#define MEXTI_LINE14   14
#define MEXTI_LINE15   15


void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch( u8 Copy_u8Line , u8 Copy_u8SenseMode );
void MEXTI_voidEnable ( u8 Copy_u8Line );
void MEXTI_voidDisable( u8 Copy_u8Line );
void MEXTI_voidSoftWareTrigger( u8 Copy_u8Line );
void MEXTI_voidSetCallBack( u8 Copy_u8Line , void (*Copy_CallBack)(void) );

#endif