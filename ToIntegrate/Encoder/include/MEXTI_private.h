#ifndef _MEXTI_PRIVATE_H
#define _MEXTI_PRIVATE_H

typedef struct{
	
	volatile u32 IMR   ;
	volatile u32 EMR   ;
	volatile u32 RTSR  ;
	volatile u32 FTSR  ;
	volatile u32 SWIER ;
	volatile u32 PR    ;
	
}EXTI_Type;


#define MEXTI ((volatile EXTI_Type*)0x40010400)

#endif