#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

task turn()
{
	while (true)
	{
		while (joy1Btn (8))
		{
			motor[motorE] = -30;
  	  motor[motorD] = -30;
  	}
  	while (joy1Btn (7))
  	{
  		motor[motorE] = 30;
  		motor[motorD] = 30;
    }
    while (joy1Btn (4))
		{
			motor[motorE] = 30;
  	  motor[motorD] = -30;
  	}
  	while (joy1Btn (2))
  	{
  		motor[motorE] = -30;
  		motor[motorD] = 30;
    }

    motor[motorE] = 0;
    motor[motorD] = 0;

  }
}



task move()
{
	while (true)
	{
	  motor[motorE] = -joystick.joy1_y1;
    motor[motorD] = joystick.joy1_y1;
  }
}

task main()
{

  StartTask(turn);
  //StartTask(move);

 while(true)
  {
    getJoystickSettings(joystick);
  }
}
