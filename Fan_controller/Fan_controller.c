#include "DC_Motor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"

int main(void){
	DcMotor_Init(); /* initialize DC Motor driver */
	LCD_init(); /* initialize LCD driver */
	ADC_ConfigType ADC_config;
	ADC_config.ref_volt=INTERNAL;  //Internal voltage reference 2.56v
	ADC_config.prescaler=DIVF8;   //FCPU/8
	ADC_init(&ADC_config);  // intitialize ADC driver
    LCD_displayStringRowColumn(0,0,"   Fan is   ");
    LCD_displayStringRowColumn(1,0,"   Temp =    C");
    while(1){
    uint8 temp= LM35_getTemperature(); //get value of temperature
    //display if fan is off
	if(temp < 30){
		LCD_moveCursor(0,10);
		LCD_displayString("OFF");
	}
	//display if fan is on
	else{
		LCD_moveCursor(0,10);
		LCD_displayString("ON ");
	}
	//display value of temperature
	LCD_moveCursor(1,10);
	if(temp >= 100)
	{
		LCD_intgerToString(temp);
	}
	else
	{
		LCD_intgerToString(temp);
		LCD_displayCharacter(' ');
	}
    if(temp < 30){
    	DcMotor_Rotate(STOP,0);
    }
    else if(temp >= 30 && temp < 60){
    	DcMotor_Rotate(CW,25);
    }
    else if(temp >= 60 && temp < 90){
        	DcMotor_Rotate(CW,50);
        }
    else if(temp >= 90 && temp < 120){
        	DcMotor_Rotate(CW,75);
        }
    else if(temp >= 120){
        	DcMotor_Rotate(CW,100);
        }

    }



}

