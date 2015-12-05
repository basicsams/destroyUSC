#pragma config(Motor,  port1,           rightBackMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           beltMotor,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           leftFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rollerMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           intakeMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           launcherLeftMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           launcherRightMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          leftBackMotor, tmotorVex393_HBridge, openLoop, reversed)

//comment
task main()
{
	while(true)
	{
		motor[launcherLeftMotor] = 60;
		motor[launcherRightMotor] = 60;

		wait1MSec(2000);

		motor[intakeMotor] = 127;
		wait1Msec(2000);
		motor[intakeMotor] = 0;

		motor[intakeMotor] = 127;
		wait1Msec(2000);
		motor[intakeMotor] = 0;

		motor[intakeMotor] = 127;
		wait1Msec(2000);
		motor[intakeMotor] = 0;

		motor[intakeMotor] = 127;
		wait1Msec(2000);
		motor[intakeMotor] = 0;
	}


}
