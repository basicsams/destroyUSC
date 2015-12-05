#pragma config(Motor,  port1,           rightBackMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           beltMotor,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           leftFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rollerMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           intakeMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           launcherLeftMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           launcherRightMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          leftBackMotor, tmotorVex393_HBridge, openLoop, reversed)

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////


void rotate()
{
		motor[rightFrontMotor] = 100;
		motor[rightBackMotor] = 100;

		motor[leftFrontMotor] = -100;
		motor[leftBackMotor] = -100;

		wait1Msec(450);

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
	motor[launcherLeftMotor] = 65;
	motor[launcherRightMotor] = 65;

	wait1Msec(1000);
	drive(1250, 100);

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

	wait1Msec(10000);

	motor[rollerMotor] = 127;								//...suck in balls.
	motor[beltMotor] = 127;

	drive(2000, 100);

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
	int threshold = 10;
	int Btn5UToggleState = 0;
	int Btn5UPressed = 0;
	int Btn5DToggleState = 0;
	int Btn5DPressed = 0;
	int Btn7UToggleState = 0;
	int Btn7UPressed = 0;
	int Btn7DToggleState = 0;
	int Btn7DPressed = 0;
	int speed = 65;

	while(1 == 1)
	{

		// DRIVE CONTROL - Tank drive style.
		//*******************************************************************
		//Right side of the robot is controlled by the right joystick, Y-axis
		if (abs(vexRT[Ch2]) > threshold)
		{
			motor[rightFrontMotor] = vexRT[Ch2];
			motor[rightBackMotor] = vexRT[Ch2];
		}
		else
		{
			motor[rightFrontMotor] = 0;
			motor[rightBackMotor] = 0;
		}
		//Left side of the robot is controlled by the left joystick, Y-axis
		if (abs(vexRT[Ch3]) > threshold)
		{
			motor[leftFrontMotor] = vexRT[Ch3];
			motor[leftBackMotor] = vexRT[Ch3];
		}
		else
		{
			motor[leftFrontMotor] = 0;
			motor[leftBackMotor] = 0;
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

		//=========================================

		// increase speed
		if (vexRT[Btn7U] == 1)
		{
			if (!Btn7UPressed)
			{
				Btn7UToggleState = 1 - Btn7UToggleState;
				Btn7UPressed = 1;
				if (Btn7UToggleState == 1)
				{
					speed = speed + 1;
				}
			}
		}
		else
		{
			Btn7UPressed = 0;
		}


		// decrease speed
		if (vexRT[Btn7D] == 1)
		{
			if (!Btn7DPressed)
			{
				Btn7DToggleState = 1 - Btn7DToggleState;
				Btn7DPressed = 1;
				if (Btn7DToggleState == 1)
				{
					speed = speed - 1;
				}
			}
		}
		else
		{
			Btn7DPressed = 0;
		}

		//DEFAULTSPEED
		if (vexRT[Btn8D])
		{
			speed = 75;
		}

		/* Kills motoro!!!!
		if(vexRT[Btn7U] == 1)
		{
		speed = speed + 10;
		}
		if(vexRT[Btn7D] == 1)
		{
		speed = speed - 10;
		}
		if(vexRT[Btn8D] == 1)
		{
		speed = 80;
		}
		*/

		/*
		if(vexRT[Btn7D] == 1)
		{
		speed = 80;
		}
		if(vexRT[Btn7L] == 1)
		{
		speed = 70;
		}
		if(vexRT[Btn7U] == 1)
		{
		speed = 60;
		}
		if (vexRT[Btn7R] == 1)
		{
		speed = 50;
		}
		*/


		if (Btn5UToggleState)
		{
			motor[launcherLeftMotor] = speed;					//...activate launchers.
			motor[launcherRightMotor] = speed;
		}
		else
		{
			motor[launcherLeftMotor] = 0;						//...deactivate launchers.
			motor[launcherRightMotor] = 0;
		}
		//*******************************************************************


		// FRONT ROLLER CONTROL - "Sucks up" balls and feeds to chain intake.
		//*******************************************************************

		if (vexRT[Btn5D] == 1)										//If Button 5D is pressed...
		{
			if (!Btn5DPressed)
			{
				Btn5DToggleState = 1 - Btn5DToggleState;							//...change toggle state.
				Btn5DPressed = 1;									//...note button was pressed.
			}
		}
		else
		{
			//Btn5DToggleState = false;
			Btn5DPressed = 0;
		}

		if (Btn5DToggleState)											//If toggle state is true...
		{
			motor[rollerMotor] = 127;								//...suck in balls.
			motor[beltMotor] = 127;
		}
		else																			//If toggle state is false...
		{
			motor[rollerMotor] = 0;									//...deactivate.
			motor[beltMotor] = 0;
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
