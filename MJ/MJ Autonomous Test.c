#pragma config(Motor,  port1,           rightBackMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           beltMotor,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           leftFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rollerMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           intakeMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           launcherLeftMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           launcherRightMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          leftBackMotor, tmotorVex393_HBridge, openLoop, reversed)

/*----------------------------------------------------------------------------------------------------*\
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch2 is the Y axis for the RIGHT joystick.                             											*|
|*    2)  Ch3 is the Y axis for the LEFT joystick.                 											              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]                [Type]                [Description]                   *|
|*    Motor Port 2        rightMotors						VEX 393 Motor     		(2) Right drive motors          *|
|*    Motor Port 3        leftMotors		        VEX 393 Motor			    (2) Left drive motors           *|
|*    Motor Port 8        launcherLeftMotor     VEX 393 High Speed    (2) Left launcher motors        *|
|*    Motor Port 9        launcherRightMotor    VEX 393 High Speed    (2) Right launcher motors       *|
\*----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
void rotate()
{
		motor[rightFrontMotor] = 100;
		motor[rightBackMotor] = 100;

		motor[leftFrontMotor] = -100;
		motor[leftBackMotor] = -100;

		wait1Msec(250)

		motor[rightFrontMotor] = 0;
		motor[rightBackMotor] = 0;

		motor[leftFrontMotor] = 0;
		motor[leftBackMotor] = 0;
}

void drive(int time, int power)
{
		motor[rightFrontMotor] = power;
		motor[rightBackMotor] = power;

		motor[leftFrontMotor] = power;
		motor[leftBackMotor] = power;

		wait1Msec(time);
}

task main()
{
	while(1 == 1)
	{
		if (vexRT[Btn8D] == 1)
		{
				wait1Msec(1000);
				drive(1500, 100);

				motor[launcherLeftMotor] = 55;
				motor[launcherRightMotor] = 55;

				rotate();

				wait1Msec(5000);

				motor[intakeMotor] = 127;
				wait1Msec(1000);
				motor[intakeMotor] = 0;

				motor[intakeMotor] = 127;
				wait1Msec(1000);
				motor[intakeMotor] = 0;

				motor[intakeMotor] = 127;
				wait1Msec(1000);
				motor[intakeMotor] = 0;

				motor[intakeMotor] = 127;
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
