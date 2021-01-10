#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MEXTI_interface.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"

static void (*MEXTI_CallBack[16])(void);

void MEXTI_voidInit(void){
	
	#if ( MEXTI_LINE >= MEXTI_LINE0 ) && ( MEXTI_LINE <= MEXTI_LINE15 )
	
		MEXTI -> FTSR = 0 ;
		MEXTI -> RTSR = 0 ;
		MEXTI -> IMR  = 0 ;
	
		#if MEXTI_SENSE_MODE == MEXTI_FALLING_EDGE
		
			SET_BIT( MEXTI -> FTSR , MEXTI_LINE );
		
		#elif MEXTI_SENSE_MODE == MEXTI_RISING_EDGE
		
			SET_BIT( MEXTI -> RTSR , MEXTI_LINE );
		
		#elif MEXTI_SENSE_MODE == MEXTI_ON_CHANGE
		
			SET_BIT( MEXTI -> RTSR , MEXTI_LINE );
			SET_BIT( MEXTI -> FTSR , MEXTI_LINE );
			
		#else
			
			#warning (" Wrong Sense Mode Choice ")
		
		#endif 
	
	#else
		
		#warning (" Worning Wrong External Interrupt Line ")
		
	#endif
	
}

void MEXTI_voidSetSignalLatch( u8 Copy_u8Line , u8 Copy_u8SenseMode ){
	
	switch( Copy_u8SenseMode ){
		
		case MEXTI_FALLING_EDGE : SET_BIT( MEXTI -> FTSR , Copy_u8Line ); break;
		case MEXTI_RISING_EDGE  : SET_BIT( MEXTI -> RTSR , Copy_u8Line ); break;
		
		case MEXTI_ON_CHANGE    : SET_BIT( MEXTI -> FTSR , Copy_u8Line );
		                          SET_BIT( MEXTI -> RTSR , Copy_u8Line ); break;
	}
	
	SET_BIT( MEXTI -> IMR , Copy_u8Line );
	
}

void MEXTI_voidEnable ( u8 Copy_u8Line ){
	
	SET_BIT( MEXTI -> IMR , Copy_u8Line );
	
}

void MEXTI_voidDisable( u8 Copy_u8Line ){
	
	CLR_BIT( MEXTI -> IMR , Copy_u8Line );
	
}

void MEXTI_voidSoftWareTrigger( u8 Copy_u8Line ){
	
	SET_BIT( MEXTI -> SWIER , Copy_u8Line );
	
}

void MEXTI_voidSetCallBack( u8 Copy_u8Line , void (*Copy_CallBack)(void) ){
	
	MEXTI_CallBack[ Copy_u8Line ] = Copy_CallBack ;
	
}

void EXTI0_IRQHandler(void){
	
	MEXTI_CallBack[0]();
	SET_BIT( MEXTI -> PR , 0 );
	
}

void EXTI1_IRQHandler(void){
	
	MEXTI_CallBack[1]();
	SET_BIT( MEXTI -> PR , 1 );
	
}

void EXTI2_IRQHandler(void){
	
	MEXTI_CallBack[2]();
	SET_BIT( MEXTI -> PR , 2 );
	
}

void EXTI3_IRQHandler(void){
	
	MEXTI_CallBack[3]();
	SET_BIT( MEXTI -> PR , 3 );
	
}

void EXTI4_IRQHandler(void){
	
	MEXTI_CallBack[4]();
	SET_BIT( MEXTI -> PR , 4 );
	
}

void EXTI9_5_IRQHandler(void){
	
	if( GET_BIT( MEXTI -> PR , 5 ) == 1 ){
		
		MEXTI_CallBack[5]();
		SET_BIT( MEXTI -> PR , 5 );
		
	}
	if( GET_BIT( MEXTI -> PR , 6 ) == 1 ){
		
		MEXTI_CallBack[6]();
		SET_BIT( MEXTI -> PR , 6 );
		
	}
	if( GET_BIT( MEXTI -> PR , 7 ) == 1 ){
		
		MEXTI_CallBack[7]();
		SET_BIT( MEXTI -> PR , 7 );
		
	}
	if( GET_BIT( MEXTI -> PR , 8 ) == 1 ){
		
		MEXTI_CallBack[8]();
		SET_BIT( MEXTI -> PR , 8 );
		
	}
	if( GET_BIT( MEXTI -> PR , 9 ) == 1 ){
		
		MEXTI_CallBack[9]();
		SET_BIT( MEXTI -> PR , 9 );
		
	}
	
}

void EXTI15_10_IRQHandler(void){
	
	if( GET_BIT( MEXTI -> PR , 10 ) == 1 ){
		
		MEXTI_CallBack[10]();
		SET_BIT( MEXTI -> PR , 10 );
		
	}
	if( GET_BIT( MEXTI -> PR , 11 ) == 1 ){
		
		MEXTI_CallBack[11]();
		SET_BIT( MEXTI -> PR , 11 );
		
	}
	if( GET_BIT( MEXTI -> PR , 12 ) == 1 ){
		
		MEXTI_CallBack[12]();
		SET_BIT( MEXTI -> PR , 12 );
		
	}
	if( GET_BIT( MEXTI -> PR , 13 ) == 1 ){
		
		MEXTI_CallBack[13]();
		SET_BIT( MEXTI -> PR , 13);
		
	}
	if( GET_BIT( MEXTI -> PR , 14 ) == 1 ){
		
		MEXTI_CallBack[14]();
		SET_BIT( MEXTI -> PR , 14 );
		
	}
	if( GET_BIT( MEXTI -> PR , 15 ) == 1 ){
		
		MEXTI_CallBack[15]();
		SET_BIT( MEXTI -> PR , 15 );
		
	}
	
}
