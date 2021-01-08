/*
 * main.c
 *  Created on: Dec 30, 2020
 *  Created on: Dec 29, 2020
 *      Author: AlaaElnagar
 */




/*@ brief  This driver based on Two main structures
 *
 * 1- MGPIO_t this structure used to define used GPIO PIN AND PORT    EXIST in interface.h file
 *
 * 2-DHT_t   this structure used to hold the humidity and temperature results after making instance array of it
 * */

/************Don't forget to replace systic in Prog.c with timer1 ****************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MNVIC_interface.h"
#include "Timer_interface.h"
#include "DHT11_Interface.h"
#include "MSTK_interface.h"

/*Make instance from MGPIO_t struct and assigen the used PIN number  and PORT  number to work as dht11 pin and in prog.h every thing will be assigend automatically  */
	MGPIO_t S1_dht11MGpio = {MGPIO_PORTA,MGPIO_PIN0} ;


void dht11TaskX(){

	/*Make instance from  DHT_t  which return pointer to struct */
			 DHT_t volatile  *Dht_sensor1_Data=DHT11_VidReciveData(S1_dht11MGpio);
	/*Check if the function >>>DHT11_VidReciveData<< which return struct address that contains the data of of temperature and humidity is not NULL */
			 if (Dht_sensor1_Data != NULL){

					 Dht_sensor1_Data[DHT11_TEMP_I].data;
					 Dht_sensor1_Data[DHT11_HUMD_I].data ;

			 }
}


int main(void)
{

	MRCC_voidInitSysClock();//Initialization System Clock Speed 8Mhz Crystel
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOA_EN );//Enable GPIOA Peripheral Clock
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOB_EN );//Enable GPIOb Peripheral Clock
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_GPIOC_EN );//Enable GPIOc Peripheral Clock
	MRCC_voidEnablePerClock( MRCC_APB2 , MRCC_TIMER_1_EN) ;
	MSTK_voidInit();




	 while(1);

	return 0;

            }


