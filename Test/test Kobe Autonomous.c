#pragma config(Motor,  port2,           rightFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           intakeMotor,   tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           launcherLeftMotor, tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           launcherRightMotor, tmotorVex393HighSpeed_MC29, openLoop)

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

task main()
{
	//What happens: launchers turn on, robot goes forward for 5 seconds, stops, dumps all the balls, then comes back.
	while(true)
	{
		drive(1, 5000);
		activateLauncher();
		wait1Msec(1000);
		activateIntake();
	}
}
