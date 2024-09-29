#include "std_types.h"
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

typedef enum {
    CW,
    ACW,
    STOP
}DcMotor_State;

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
