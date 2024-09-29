#include "common_macros.h"
#include "DC_Motor.h"
#include "gpio.h"
#include"PWM.h"


void DcMotor_Init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	 switch (state) {
	        case CW:
	        	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);  // CW direction
	        	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW); // Clear ACW direction
	            break;

	        case ACW:
	        	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);  // ACW direction
	        	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);// Clear CW direction
	            break;

	        case STOP:
	        	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	        	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW); // Stop both directions
	            break;
	    }
	 uint8 duty_cycle=((speed*255)/100);  //to adjust duty cycle value when PWM_Timer0_Start is called
	 PWM_Timer0_Start(duty_cycle);  // generate duty cycle to control speed of motor


}
