/*
 *main.c


 *
 *  Created on: Dec 29, 2020
 *      Author: AlaaElnagar
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "MSTK_interface.h"
#include "MDMA_interface.h"
#include "MEXTI_interface.h"
#include "MAFIO_interface.h"
#include "Timer_interface.h"
#include "STMU_interface.h"
#include "SensorsPinsInerface.h"


volatile u32 Enc_U32Counter        ;
volatile u32 Enc_U32Revelution     ;
volatile u32 Enc_U32NewRevelution  ;
volatile u32 Enc_U32OldRevelution  ;

Enc_Date_t encoder1;

/*Encoder Task to be inserted as it is in the OS*/

void TASK1_vIdEncoderFunc(){
	/*To get number of time that this task occur to get give RPM each Minute*/
	encoder1.ENC_u8TaskEnteryCounts+=1;
	/*Iterate in this loop to get maximum pulse nmber untill finishing of task time*/
while(1){
	/*Getting Encoder data and detect if there is new pulse */
Enc_vIdGetEncData(&encoder1,1,100 ) ;

}


}
void TASK2_vidThermistorFunc(){



}


void TASK3_vidBatteryLvlFunc(){



}



int main(void)
{

	 SensorsPin_vIdInit ();

	Tasks_t TASK1 ,TASK2,TASK3;

	TASK1.Task_Func = TASK1_vIdEncoderFunc;
	TASK1.Periodicity = 1;
	TASK2.Task_Func = TASK2_vidThermistorFunc;
	TASK2.Periodicity = 5;
	TASK3.Task_Func = TASK3_vidBatteryLvlFunc;
	TASK3.Periodicity = 10;



	STMU_VidAddTask(TASK1) ;
	STMU_VidAddTask(TASK2) ;
	STMU_VidAddTask(TASK3) ;



	/*This function is responsible for starting TMU scheduler with a specific system tick (from 0 to 16777ms)*/
	STMU_VidStartSchudler(100);

	while(1);

	return 0;
}























//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//#include "MRCC_interface.h"
//#include "MRCC_interface.h"
//#include "MGPIO_interface.h"
//#include "MNVIC_interface.h"
//#include "MSTK_interface.h"
//#include "MDMA_interface.h"
//#include "MEXTI_interface.h"
//#include "MAFIO_interface.h"
//#include "Timer_interface.h"
//#include "STMU_interface.h"
//#include "SensorsPinsInerface.h"
//

//
//
//
//
//
//
//
//
//
//
//u8  x = 0 						   ;
//volatile u32 Enc_U32Counter        ;
//volatile u32 Enc_U32Revelution     ;
//volatile u32 Enc_U32NewRevelution  ;
//volatile u32 Enc_U32OldRevelution  ;
//
//
//void Timr1_VidIsrFunc(void){
///*To get amount of RPM */
//
//}
//
//
//void EXTI_VidIsrFunc(void){
//
//
//if(MGPIO_u8GetPinValue(MGPIO_PORTB,12)){
//
//	Enc_U32Counter++;
//
//}
//
//		if (Enc_U32Counter %70 ==0){
//			x^=1;
//			MGPIO_voidSetPinValue    ( MGPIO_PORTC , MGPIO_PIN13, x );
//
//			x*=1;
//
//		}
//
//
//
//	//}
//
////	if (Enc_U32Counter % 70 == 0 &&Enc_U32Counter >0){
////
////		Enc_U32Counter=	Enc_U32Counter *1;
////
////		Enc_U32Counter=	Enc_U32Counter *1;
//////	}
////
////	Enc_U32Revelution  = Enc_U32Counter / 20 ;
////
////	Enc_U32NewRevelution = Enc_U32Revelution ;
////
////	if (Enc_U32NewRevelution != Enc_U32OldRevelution){
//
//	//MGPIO_voidSetPinValue    ( MGPIO_PORTC , MGPIO_PIN13, MGPIO_HIGH );
////
////}
////
////else{
////	MGPIO_voidSetPinValue    ( MGPIO_PORTC , MGPIO_PIN13, MGPIO_LOW );
////
////}
////
////Enc_U32OldRevelution =  Enc_U32Revelution ;
////
//
//}
//
//
//int main(void)
//{
//
//	MRCC_voidInitSysClock();//Initialization System Clock Speed 8Mhz Crystel
//	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOB_EN   );//Enable GPIOA Peripheral Clock
//	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOC_EN   );//Enable GPIOA Peripheral Clock
//	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_AFIO_EN    );
//	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_TIMER_1_EN );
//
//	/*Timer 1 */
//
//	TIM_ConfigType    timer1                              ;
//	timer1.Counter_State     = Enable_CNT                 ;
//	timer1.PrescalerVal     = 8                           ;
//	timer1.Direction_State = UpCounter                    ;
//	TIM_vInit(TIMER1 , &timer1)                           ;
//
//
//	TIM_vSetIntervalPeriodic(TIMER1,60 ,TIM_TICKS_S	 ,&Timr1_VidIsrFunc) ;
//
//
//
//
//	MAFIO_voidInit();
//	MAFIO_voidExternalInterruptRemap( MAFIO_EXTI13 , MAFIO_GPIOB );
//
//	MGPIO_voidSetPinDirection( MGPIO_PORTC, MGPIO_PIN13 , MGPIO_OUTPUT_10MHZ_PP );
//
//		MGPIO_voidSetPinDirection( MGPIO_PORTB, MGPIO_PIN14 , MGPIO_INPUT_PULLUP_PULLDOWN );
//		MGPIO_voidSetPinDirection( MGPIO_PORTB, MGPIO_PIN12 , MGPIO_INPUT_PULLUP_PULLDOWN);
//		MGPIO_voidSetPinDirection( MGPIO_PORTB, MGPIO_PIN13, MGPIO_INPUT_PULLUP_PULLDOWN );
//
//	   MGPIO_voidSetPinValue    ( MGPIO_PORTB, MGPIO_PIN14 , MGPIO_HIGH );
//	MGPIO_voidSetPinValue    ( MGPIO_PORTB, MGPIO_PIN13,  MGPIO_HIGH );
//		//MGPIO_voidSetPinValue    ( MGPIO_PORTB, MGPIO_PIN12 , MGPIO_HIGH );
//
//	/*Enable EXTI Using nvic*/
//		/*realated to Encoder incremment in right direction */
//		MNVIC_voidEnablePeri( MNVIC_EXTI13_IRQ );
//MNVIC_voidEnablePeri( MNVIC_TMR1_UP_IRQ );
//
//
//		MEXTI_voidSetCallBack( MEXTI_LINE13 , EXTI_VidIsrFunc );
//
//		MEXTI_voidSetSignalLatch( MEXTI_LINE13 , MEXTI_FALLING_EDGE);
//	while(1){
//
//
//
//
//
//
//	}
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//









