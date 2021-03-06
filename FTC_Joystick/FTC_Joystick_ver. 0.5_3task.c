#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,      ,             tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

task move()
{
	static int speed = 50, m_speed = -50, slow_speed = 20, slow_m_speed = -20;

	while (joy1Btn(10) != 1)
  {}


	while (true)
	{
		if (joy1Btn (7))
		{
			while (joy1Btn (7)) /* turn left */
		  {
			  motor[motorE] = speed;
			  motor[motorD] = speed;
			  motor[motorF] = speed;
			  motor[motorG] = speed;
		  }

		  while (motor[motorE] >= 0)
		  {
		    motor[motorE]-= 1;
			  motor[motorD]-= 1;
			  motor[motorF]-= 1;
			  motor[motorG]-= 1;
			  wait1Msec(2);
		  }
		}

		if (joy1Btn (8))
	  {
	  	while (joy1Btn (8)) /* turn right*/
		  {
		  	motor[motorE] = m_speed;
			  motor[motorD] = m_speed;
		  	motor[motorF] = m_speed;
		  	motor[motorG] = m_speed;
		  }

		  while (motor[motorE] <= 0)
		  {
		  	motor[motorE]+= 1;
			  motor[motorD]+= 1;
		  	motor[motorF]+= 1;
		  	motor[motorG]+= 1;
		  	wait1Msec(2);
		  }
		}

		if (joy1Btn (4))
		{
			while (joy1Btn (4)) /* move forward*/
			{
				motor[motorE] = m_speed;
				motor[motorD] = m_speed;
				motor[motorF] = speed;
				motor[motorG] = speed;
			}

			while (motor[motorG] >= 0)
			{
				motor[motorE]+= 1;
				motor[motorD]+= 1;
				motor[motorF]-= 1;
				motor[motorG]-= 1;
				wait1Msec(2);
			}
		}

		if (joy1Btn (2))
	  {
		  while (joy1Btn (2)) /* move backward */
			{
				motor[motorE] = speed;
				motor[motorD] = speed;
				motor[motorF] = m_speed;
				motor[motorG] = m_speed;
			}

			while (motor[motorE] >= 0)
			{
				motor[motorE]-= 1;
				motor[motorD]-= 1;
				motor[motorF]+= 1;
				motor[motorG]+= 1;
			}
		}

		if (joy1Btn (1))
		{
			while (joy1Btn (1)) /* move left */
		  {
				motor[motorE] = speed;
				motor[motorD] = m_speed;
				motor[motorF] = m_speed;
				motor[motorG] = speed;
			}

			while (motor[motorE] >= 0)
		  {
		  	motor[motorE]-= 1;
				motor[motorD]+= 1;
				motor[motorF]+= 1;
				motor[motorG]-= 1;
			}
		}

		if (joy1Btn (3))
		{
		  while (joy1Btn (3)) /* move right */
			{
				motor[motorE] = m_speed;
				motor[motorD] = speed;
				motor[motorF] = speed;
				motor[motorG] = m_speed;
			}

			while (motor[motorD] >= 0)
			{
				motor[motorE]+= 1;
				motor[motorD]-= 1;
				motor[motorF]-= 1;
				motor[motorG]+= 1;
			}
		}

		if (joystick.joy1_TopHat == 0)
		{
		  while (joystick.joy1_TopHat == 0) /* slow move forward */
			{
				motor[motorE] = slow_m_speed;
				motor[motorD] = slow_m_speed;
				motor[motorF] = slow_speed;
				motor[motorG] = slow_speed;
			}

			while (motor[motorF] >= 0)
		  {
		  	motor[motorE]+= 1;
				motor[motorD]+= 1;
				motor[motorF]-= 1;
				motor[motorG]-= 1;
		  }
		}

		if (joystick.joy1_TopHat == 4)
		{
			while (joystick.joy1_TopHat == 4) /* slow move backward */
			{
				motor[motorE] = slow_speed;
				motor[motorD] = slow_speed;
				motor[motorF] = slow_m_speed;
				motor[motorG] = slow_m_speed;
			}

			while (motor[motorE] >= 0)
			{
				motor[motorE]-= 1;
				motor[motorD]-= 1;
				motor[motorF]+= 1;
				motor[motorG]+= 1;
			}
		}

		if (joystick.joy1_TopHat == 6)
		{
			while (joystick.joy1_TopHat == 6) /* slow move left */
			{
				motor[motorE] = slow_speed;
				motor[motorD] = slow_m_speed;
				motor[motorF] = slow_m_speed;
				motor[motorG] = slow_speed;
			}

			while (motor[motorE] >= 0)
			{
				motor[motorE]-= 1;
				motor[motorD]+= 1;
				motor[motorF]+= 1;
				motor[motorG]-= 1;
			}
		}

		if (joystick.joy1_TopHat == 2)
		{
			while (joystick.joy1_TopHat == 2) /* slow move right */
			{
				motor[motorE] = slow_m_speed;
				motor[motorD] = slow_speed;
				motor[motorF] = slow_speed;
				motor[motorG] = slow_m_speed;
			}
			while (motor[motorD] >= 0)
			{
				motor[motorE]+= 1;
				motor[motorD]-= 1;
				motor[motorF]-= 1;
				motor[motorG]+= 1;
			}
		}

		if (joy1Btn (6))
		{
		  while (joy1Btn (6)) /* slow turn right*/
			{
				motor[motorE] = slow_m_speed;
				motor[motorD] = slow_m_speed;
				motor[motorF] = slow_m_speed;
				motor[motorG] = slow_m_speed;
			}
		  while (motor[motorE] <= 0)
		  {
		  	motor[motorE]+= 1;
				motor[motorD]+= 1;
				motor[motorF]+= 1;
				motor[motorG]+= 1;
		  }
		}

		if (joy1Btn (5))
		{
			while (joy1Btn (5)) /* slow turn left */
			{
				motor[motorE] = slow_speed;
				motor[motorD] = slow_speed;
				motor[motorF] = slow_speed;
				motor[motorG] = slow_speed;
			}
			while (motor[motorE] >= 0)
			{
				motor[motorE]-= 1;
				motor[motorD]-= 1;
				motor[motorF]-= 1;
				motor[motorG]-= 1;
			}
		}

		while (joy1Btn (9)) /* turn servo - flag */
		  servo[servo1] = 0; /* 0 - Full Power/ Speed Reverse; 127 - Stop; 256 - Full Power/ Speed Forward */

		servo[servo1] = 127;
	}
}

task capture ()
{
	static int move_h =	80, move_d = -80;

	while (true)
	{
		if (joy2Btn(4))
		  motor[motorH] = move_h;

		if (joy2Btn(2))
		  motor[motorH] = move_d;

		motor[motorH] = 0;
	}
}

task main ()
{
	StartTask(move);
	StartTask(capture);

	while (true)
		getJoystickSettings(joystick);
}
