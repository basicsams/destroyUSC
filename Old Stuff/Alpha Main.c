#pragma config(Motor,  port1,           rightBackMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           beltMotor,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           leftFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rollerMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           intakeMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           launcherLeftMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           launcherRightMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          leftBackMotor, tmotorVex393_HBridge, openLoop, reversed)

/*
Motors:
4 drive motors
4 launcher motors --> 2 Y-splitters
1 lift motor
1 roller motor
*/

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
task main()
{
	int threshold = 10;
	int Btn5UToggleState = 0;			// BOOLEAN doesn't work because of the toggle = 1 - toggle.
	int Btn5UPressed = 0;
	int Btn5DToggleState = 0;
	int Btn5DPressed = 0;

	while(1 == 1)
	{

		// DRIVE CONTROL - Tank drive style.
		//*******************************************************************
		//Right side of the robot is controlled by the right joystick, Y-axis
		if (abs(vexRT[Ch2]) > threshold)					// Eliminate noise from joystick// not perfectly at neutral position.
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
		/*if (vexRT[Btn5U] == 1 && !Btn5UPressed)		//If Button 5U is pressed...
		{
			Btn5UToggleState = true;								//...change toggle state.
			Btn5UPressed = true;										//...note button was pressed.
		}
		else
		{
			Btn5UPressed = false;
			Btn5UToggleState = false;
		}

		if (Btn5UToggleState)											//If toggle state is true...
		{
			motor[launcherLeftMotor] = 127;					//...activate launchers.
			motor[launcherRightMotor] = 127;
		}
		else																			//If toggle state is false...
		{
			motor[launcherLeftMotor] = 0;						//...deactivate launchers.
			motor[launcherRightMotor] = 0;
		}
		*/

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
		/*

		if (vexRT[Btn7D])
			Btn5DPressed = true;
		if (vexRT[Btn7U])
			Btn5DPressed = false;

		if (Btn5DPressed == true)
			motor[rollerMotor] = 127;
		else
			motor[rollerMotor] = 0;
*/

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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
