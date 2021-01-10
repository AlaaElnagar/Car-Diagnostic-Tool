/*
 * SensorsProg.c

 *
 *  Created on: Dec 29, 2020
 *      Author: AlaaElnagar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "SensrsPinsConfig.h"
#include "SensorsPinsInerface.h"

u8  volatile Glob_U8chALaststate ;
u8  volatile Glob_U8chBLaststate ;
u8  volatile Glob_U8Periodicity_Counter ;
u32 volatile Glob_u32ElabsedTime ;
u32 volatile Glob_U32TotalREV ;
u32 volatile Glob_U32MinuteREV ;


/*Function to intialize All system sensors Pins */

void SensorsPin_vIdInit (void){

	//Initialization System Clock Speed 8Mhz Crystel
	MRCC_voidInitSysClock();
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOA_EN   );
//	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOB_EN   );
//	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOC_EN   );

	MGPIO_voidSetPinDirection(ENCODER_PA_PORT,ENCODER_A_PIN,MGPIO_INPUT_FLOATING );
//	MGPIO_voidSetPinDirection(ENCODER_PB_PORT,ENCODER_B_PIN,MGPIO_INPUT_FLOATING);
//	MGPIO_voidSetPinDirection(BATTERYLVL_PORT ,ENCODER_SWITCH_PIN,MGPIO_INPUT_FLOATING);
//	MGPIO_voidSetPinDirection(MGPIO_PORTC,MGPIO_PIN13,MGPIO_OUTPUT_10MHZ_PP );

	/*Analog Input Sensors  */
//	MGPIO_voidSetPinDirection(BATTERYLVL_PORT,BATTERYLVL_PIN,MGPIO_INPUT_ANALOG );
//	MGPIO_voidSetPinDirection(THERMISTOR_PORT,THERMISTOR_PIN,MGPIO_INPUT_ANALOG );

}

/*Calling sensors intialization pins and getting Encoder Data */

void Enc_vIdGetEncData(Enc_Date_t *Enc_Data ,u8 Copy_u8TASK_Periodicity,u32 Copy_u32TickTime  ){
	/*Get number of time that This task is called in the OS*/
	Glob_U8Periodicity_Counter=Enc_Data->ENC_u8TaskEnteryCounts ;
	/*Get encoder pulse value from pin A*/
u8 volatile Loc_U8chANewstate = MGPIO_u8GetPinValue(ENCODER_PA_PORT ,ENCODER_A_PIN) ;

//u8 Loc_U8chBNewstate = MGPIO_u8GetPinValue(ENCODER_PB_PORT,ENCODER_B_PIN ) ;


/*To make sure that encoder reading state changed and not read the last pulse value*/
if (Loc_U8chANewstate==HIGH){
if (Loc_U8chANewstate != Glob_U8chALaststate){
	/*Increment pulses nmber*/
	Enc_Data -> ENC_u32Pulses +=1 ;
/*Incrementing nmber of revelution after achieving 20 pulse*/
	if (Enc_Data -> ENC_u32Pulses % ENC_PPR == 0) {

		Glob_U32TotalREV  ++ ;
		Glob_U32MinuteREV++;
	}
}

}
/*tO make sure that The comming read   is not repeated reading*/
Glob_U8chALaststate = Loc_U8chANewstate ;

/*Calculating RPM */

/*Get amount of elapsed time From the OS variables */
Glob_u32ElabsedTime =  Copy_u32TickTime *  Copy_u8TASK_Periodicity * Glob_U8Periodicity_Counter;
/*Update Encoder Date each Minute*/
if (Glob_u32ElabsedTime%MINUTE == 0){
	/*Get amount of revelutions per minute */
	Enc_Data ->ENC_u32RPM  = Glob_U32MinuteREV/60   ;
	/*Get achieved linear distance */
	Enc_Data ->ENC_f32LinerDistance = ( Glob_U32TotalREV*WHEEL_CIRCUMESTANCE(WHEEL_RADIOUS) ) ;
	/*RESET THE revelution and counts */
	Glob_U32MinuteREV = 0;
	Enc_Data->ENC_u8TaskEnteryCounts =0;
}




}
