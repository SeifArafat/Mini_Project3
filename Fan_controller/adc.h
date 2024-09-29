
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum {
	AREF,     // External AREF pin
	AvCC,     // Analog Vcc 5v
    REVERSED,     // Reversed
	INTERNAL,   // Internal voltage reference 2.56v
} ADC_ReferenceVolatge;

typedef enum {
    DIVF2_,DIVF2, DIVF4, DIVF8, DIVF16, DIVF32, DIVF64, DIVF128    //division factors
} ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
