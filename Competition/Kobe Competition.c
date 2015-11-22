#pragma config(Motor,  port2,           rightFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           intakeMotor,   tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           launcherLeftMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           launcherRightMotor, tmotorVex393HighSpeed_MC29, openLoop)


#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

// FUNCTION DEFINITIONS
void activateLauncher()
{
	motor[launcherLeftMotor] = 127;
	motor[launcherRightMotor] = 127;
}

void drive(int direction, int duration)
{
	if (direction == 1)
	{
		motor[leftFrontMotor] = 127;
		motor[rightFrontMotor] = 127;

		wait1Msec(duration);

		motor[leftFrontMotor] = 0;
		motor[rightFrontMotor] = 0;
	}
	if(direction == -1)
	{
		motor[leftFrontMotor] = -127;
		motor[rightFrontMotor] = -127;

		wait1Msec(duration);

		motor[leftFrontMotor] = 0;
		motor[rightFrontMotor] = 0;
	}
}

void activateIntake()
{
	motor[intakeMotor] = 127;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	while(true)
	{
		drive(1, 7000);
		activateLauncher();
		wait1Msec(1000);
		activateIntake();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop
		int threshold = 10;
		int Btn5UToggleState = 0;
		int Btn5UPressed = 0;
	while (true)
	{



		// DRIVE CONTROL - Tank drive style.
		//*******************************************************************
		//Right side of the robot is controlled by the right joystick, Y-axis
		if (abs(vexRT[Ch2]) > threshold)
		{
			motor[rightFrontMotor] = vexRT[Ch2];
		}
		else
		{
			motor[rightFrontMotor] = 0;
		}
		//Left side of the robot is controlled by the left joystick, Y-axis
		if (abs(vexRT[Ch3]) > threshold)
		{
			motor[leftFrontMotor] = vexRT[Ch3];
		}
		else
		{
			motor[leftFrontMotor] = 0;
		}
		//*******************************************************************


		// BALL LAUNCHER CONTROL - Shoots balls into goal.
		//*******************************************************************
		if (vexRT[Btn5U] == 1)
		{
			if (!Btn5UPressed)
			{
				Btn5UToggleState = 1 - Btn5UToggleState;
				Btn5UPressed = 1;
			}
		}
		else
		{
			Btn5UPressed = 0;
		}

		if (Btn5UToggleState)
		{
			motor[launcherLeftMotor] = 127;					//...activate launchers.
			motor[launcherRightMotor] = 127;
		}
		else
		{
			motor[launcherLeftMotor] = 0;						//...deactivate launchers.
			motor[launcherRightMotor] = 0;
		}
		//*******************************************************************

		// CHAIN INTAKE CONTROL - Lifts/stores balls and feeds to launcher.
		//*******************************************************************
		if (vexRT[Btn6U] == 1)				//If Button 6U is held...
		{
			motor[intakeMotor] = 127;		//...intake balls.
		}
		else if (vexRT[Btn6D] == 1)		//If Button 6D is held...
		{
			motor[intakeMotor] = -127;	//...eject balls.
		}
		else													//Else (neither button is held)...
		{
			motor[intakeMotor] = 0;			//...stop.
		}
		//*******************************************************************
	}
}
