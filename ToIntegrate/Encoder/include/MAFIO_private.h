#ifndef _MAFIO_PRIVATE_H_
#define _MAFIO_PRIVATE_H_

typedef struct{
	
	volatile u32 EVCR      ;
	volatile u32 MAPR      ;
	volatile u32 EXTICR[4] ;
	volatile u32 MAPR2     ;
	
	
}AFIO_Type;

#define MAFIO ((volatile AFIO_Type*)0x40010000)

#endif