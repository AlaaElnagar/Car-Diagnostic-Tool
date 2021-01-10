#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MAFIO_interface.h"
#include "MAFIO_private.h"
#include "MAFIO_config.h"

void MAFIO_voidInit( void ){
	
	MAFIO -> EXTICR[0] = 0 ;
	MAFIO -> EXTICR[1] = 0 ;
	MAFIO -> EXTICR[2] = 0 ;
	MAFIO -> EXTICR[3] = 0 ;
	
}
void MAFIO_voidExternalInterruptRemap( u8 Copy_u8Line , u8 Copy_u8PortMap ){
	
	MAFIO -> EXTICR[ Copy_u8Line / 4 ] &= ~( (0b1111)    << ( ( Copy_u8Line % 4 ) * 4 ));
	MAFIO -> EXTICR[ Copy_u8Line / 4 ] |= Copy_u8PortMap << ( ( Copy_u8Line % 4 ) * 4 );
	
}
