#pragma config(Motor,  port2,           motor1,        tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           motor2,        tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           claw_lift,     tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port5,           claw_lift2,    tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port6,           claw_lift3,    tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port7,           claw_cap,      tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	motor[port7] = 0;
	while ( 1 == 1 )
	{
		//Drive
		tankControl(Ch2, Ch3, 10);
		//Lift servo
		if(vexRT[Btn8U] == 1)
		{
			motor[port4] = 127;
			motor[port5] = 127;
			motor[port6] = 127;
		}
		else if(vexRT[Btn8D] == 1)
		{
			motor[port4] = -127;
			motor[port5] = -127;
			motor[port6] = -127;
		}
		else //if(vexRT[Btn8R] == 1)
		{
			motor[port4] = 0;
			motor[port5] = 0;
			motor[port6] = 0;
		}
		if(vexRT[Btn7U] == 1)
		{
			motor[port7] = 127;
		}
		if(vexRT[Btn7D] == 1)
		{
			motor[port7] = 0;
		}
	}
}
