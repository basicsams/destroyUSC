#pragma config(Motor,  port1,           LeftMotor,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port6,           RightMotor,    tmotorVex393_HBridge, openLoop, encoderPort, None)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	bool done = false;
	int speed = 1;

	while (!done)
	{
		motor[LeftMotor] = 127/speed;
    motor[RightMotor] = 127/speed;

    if(vexRT[Btn6U] == 1)
    {
    	speed = 2;								// half
    }
    if(vexRT[Btn6D] == 1)
    {
      speed = 3;								// third
    }
    if(vexRT[Btn5U] == 1)
    {
      speed = 4;								//quarter
    }
    if (vexRT[Btn5D] == 1)
    {
    	speed = 5;								//fifth
    }
}
}