#include  "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDMA_interface.h"
#include "MDMA_private.h"
#include "MDMA_config.h"

void (*MDMA_CallBack[7])(void);

void MDMA_voidSetConfiguratin( u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8Mode    ,
							   u8 Copy_u8Pinc    , u8 Copy_u8Minc      , u8 Copy_u8PerSize ,
							   u8 Copy_u8MemSize , u8 Copy_u8ChannelPriority                 )
							
{
	
	CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 0 );
	
	while( GET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 0 ) == 1 );
	
	if( Copy_u8Direction == MDMA_MEM_TO_MEM ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 14 );
		
	}else if( Copy_u8Direction == MDMA_MEM_TO_PER ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 4 );
		
	}else if( Copy_u8Direction == MDMA_PER_TO_MEM ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 4 );
		
	}
								
	if( Copy_u8Mode == MDMA_ENABLE_CIRC ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 5 );
		
	}else if ( Copy_u8Mode == MDMA_DISABLE_CIRC ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 5 );
		
	}	

	if( Copy_u8Pinc == MDMA_PER_INC_EN ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 6 );
		
	}else if ( Copy_u8Pinc == MDMA_PER_INC_DIS ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 6 );
		
	}
	
	if( Copy_u8Minc == MDMA_MEM_INC_EN ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 7 );
		
	}else if ( Copy_u8Minc == MDMA_MEM_INC_DIS ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 7 );
		
	}
	
	if( Copy_u8PerSize == MDMA_BYTE ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 8 );
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 9 );
		
	}else if( Copy_u8PerSize == MDMA_HALF_WORD ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 8 );
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 9 );
		
	}else if( Copy_u8PerSize == MDMA_WORD ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 8 );
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 9 );
		
	}
	
	if( Copy_u8MemSize == MDMA_BYTE ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 10 );
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 11 );
		
	}else if( Copy_u8PerSize == MDMA_HALF_WORD ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 10 );
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 11 );
		
	}else if( Copy_u8PerSize == MDMA_WORD ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 10 );
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 11 );
		
	}
	
	if( Copy_u8ChannelPriority == MDMA_LOW ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 12 );
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 13 );
		
	}else if( Copy_u8ChannelPriority == MDMA_MEDIUM ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 12 );
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 13 );
		
	}else if( Copy_u8ChannelPriority == MDMA_HIGH ){
		
		CLR_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 12 );
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 13 );
		
	}
	else if( Copy_u8ChannelPriority == MDMA_VERY_HIGH ){
		
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 12 );
		SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 13 );
		
	}
								
								
}


void MDMA_voidEnable( u8 Copy_u8Channel ){
	
	MDMA_voidClearFlag( Copy_u8Channel , MDMA_GIF  );
	MDMA_voidClearFlag( Copy_u8Channel , MDMA_TCIF );
	MDMA_voidClearFlag( Copy_u8Channel , MDMA_HTIF );
	MDMA_voidClearFlag( Copy_u8Channel , MDMA_TEIF );
	
	SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , 0 );
	
}

void MDMA_voidDisable( u8 Copy_u8Channel ){
	
	MDMA -> CHANNEL[ Copy_u8Channel ] . CCR = 0 ;
	
}

void MDMA_voidInterruptEnable( u8 Copy_u8Channel , u8 Copy_u8InterruptType ){
	
	SET_BIT( MDMA -> CHANNEL[ Copy_u8Channel ].CCR , Copy_u8InterruptType );
	
}

void MDMA_voidSetAddress( u8 Copy_u8Channel , u32 * Copy_PeripheralAddress , u32 * Copy_MemoryAddress , u16 Copy_u16NDT ){

	MDMA -> CHANNEL[ Copy_u8Channel ].CPAR  = (u32)Copy_PeripheralAddress ;
	MDMA -> CHANNEL[ Copy_u8Channel ].CMAR  = (u32)Copy_MemoryAddress     ;
	MDMA -> CHANNEL[ Copy_u8Channel ].CNDTR = Copy_u16NDT ;
	
}

void MDMA_voidClearFlag( u8 Copy_u8Channel , u8 Copy_u8Flag ){
	
	Copy_u8Channel *= 4 ;
	MDMA -> IFCR = 1 <<  ( Copy_u8Channel + Copy_u8Flag ) ;
	//SET_BIT( MDMA -> IFCR , ( Copy_u8Channel + Copy_u8Flag ));
	
}

u8 MDMA_u8GetFlag( u8 Copy_u8Channel , u8 Copy_u8Flag ){
	
	u8 LOC_u8Result = 0;
	
	Copy_u8Channel *= 4 ;
	
	LOC_u8Result = GET_BIT( MDMA -> ISR , ( Copy_u8Channel + Copy_u8Flag ) );
	
	return LOC_u8Result;
	
}

void MDMA_voidSetCallBack( u8 Copy_u8Channel , void(*ptr)(void) ){
	
	MDMA_CallBack[ Copy_u8Channel ] = ptr ;
	
}

void DMA1_Channel1_IRQHandler(void){
	
	MDMA_CallBack[0]();
	
}
void DMA1_Channel2_IRQHandler(void){
	
	MDMA_CallBack[1]();
	
}
void DMA1_Channel3_IRQHandler(void){
	
	MDMA_CallBack[2]();
	
}
void DMA1_Channel4_IRQHandler(void){
	
	MDMA_CallBack[3]();
	
}
void DMA1_Channel5_IRQHandler(void){
	
	MDMA_CallBack[4]();
	
}
void DMA1_Channel6_IRQHandler(void){
	
	MDMA_CallBack[5]();
	
}
void DMA1_Channel7_IRQHandler(void){
	
	MDMA_CallBack[6]();
	
}
