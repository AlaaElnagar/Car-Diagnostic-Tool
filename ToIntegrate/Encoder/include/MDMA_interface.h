

#ifndef _MDMA_INTERFACE_
#define _MDMA_INTERFACE_


#define MDMA_GIF   0
#define MDMA_TCIF  1
#define MDMA_HTIF  2
#define MDMA_TEIF  3

#define MDMA_CHANNEL1     0
#define MDMA_CHANNEL2	  1
#define MDMA_CHANNEL3	  2	
#define MDMA_CHANNEL4     3
#define MDMA_CHANNEL5     4
#define MDMA_CHANNEL6     5
#define MDMA_CHANNEL7     6


#define MDMA_TCIE 1
#define MDMA_HTIE 2
#define MDMA_TEIE 3



#define MDMA_MEM_TO_MEM  0
#define MDMA_MEM_TO_PER  1
#define MDMA_PER_TO_MEM  2

#define MDMA_ENABLE_CIRC   0 
#define MDMA_DISABLE_CIRC  1

#define MDMA_PER_INC_EN    0
#define MDMA_PER_INC_DIS   1

#define MDMA_MEM_INC_EN    0
#define MDMA_MEM_INC_DIS   1

#define MDMA_BYTE         0
#define MDMA_HALF_WORD    1
#define MDMA_WORD         2

#define MDMA_LOW			0
#define MDMA_MEDIUM			1
#define MDMA_HIGH			2
#define MDMA_VERY_HIGH		3


void MDMA_voidSetConfiguratin( u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8Mode    ,
							   u8 Copy_u8Pinc    , u8 Copy_u8Minc      , u8 Copy_u8MemSize ,
							   u8 Copy_u8PerSize , u8 Copy_u8ChannelPriority                 );

void MDMA_voidEnable( u8 Copy_u8Channel );

void MDMA_voidDisable( u8 Copy_u8Channel );

void MDMA_voidInterruptEnable( u8 Copy_u8Channel , u8 Copy_u8InterruptType );

void MDMA_voidSetAddress( u8 Copy_u8Channel , u32 * Copy_PeripheralAddress , u32 * Copy_MemoryAddress , u16 Copy_u16NDT );

void MDMA_voidClearFlag( u8 Copy_u8Channel , u8 Copy_u8Flag );

u8 MDMA_u8GetFlag( u8 Copy_u8Channel , u8 Copy_u8Flag );

void MDMA_voidSetCallBack( u8 Copy_u8Channel , void(*ptr)(void) );

#endif