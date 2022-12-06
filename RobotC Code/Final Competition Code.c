// Vex Team 45501E
//port2 is left, port3 is right
#pragma config(Motor,  port2,           motor1,        tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           motor2,        tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           servo1,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           servo2,        tmotorServoStandard, openLoop)
#pragma platform(VEX)
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
void pre_auton()
{
	bStopTasksBetweenModes = true;
}
task autonomous()
{

}
task usercontrol()
{
	while ( 1 == 1 )
	{
		//Drive
		tankControl(Ch2, Ch3, 10);
		//Lift servo
		if(vexRT[Btn8U] == 1)
		{
			motor[port4] = 127;
		}
		else if(vexRT[Btn8D] == 1)
		{
			motor[port4] = -127;
		}
		else if(vexRT[Btn8R] == 1)
		{
			motor[port4] = 0;
		}
		//Claw Servo
		if(vexRT[Btn6U] == 1)
		{
			motor[port5] = 120;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[port5] = -115;
		}
	}
}
