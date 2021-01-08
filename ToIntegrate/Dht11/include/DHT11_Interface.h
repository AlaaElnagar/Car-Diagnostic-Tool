/*
 *
 *
 *  Created on: Dec 30, 2020
 *      Author: AlaaElnagar
 */
#ifndef DHT11_INTERFACE_H_
#define DHT11_INTERFACE_H_

#define    DHT11_TEMP_I 				2
#define    DHT11_TEMP_D			      	3
#define    DHT11_HUMD_I			        0
#define    DHT11_HUM_D			        1
#define    CHECK_SUM					4


typedef struct {

	u8 data;

}DHT_t ;

typedef struct {

	u8 DHT11_PORT;
	u8 DHT11_PIN;

}MGPIO_t;

typedef enum {

	Sum_ok,
	Sum_Nok
}Checksum_enut;




DHT_t *DHT11_VidReciveData(MGPIO_t Copy_StMGpioPin);







#endif /* DHT11_INTERFACE_H_ */
