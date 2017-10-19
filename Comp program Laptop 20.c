#pragma config(Sensor, in1,    mobile1,        sensorPotentiometer)
#pragma config(Sensor, in2,    mobile2,        sensorPotentiometer)
#pragma config(Motor,  port2,           left,          tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           mobileL,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           scissorL1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           scissorL2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           scissorR1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           scissorR2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           mobileR,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           right,         tmotorVex393_MC29, openLoop, reversed, driveRight)


#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"

void pre_auton()
{

}
void go_front(int time, int speed=127)
{
	motor[left]=speed;
	motor[right]=speed;
	wait1Msec(time);
	motor[left]=0;
	motor[right]=0;
}
void go_back(int time, int speed=-127)
{
	motor[left]=speed;
	motor[right]=speed;
	wait1Msec(time);
	motor[left]=0;
	motor[right]=0;
}
void turn(int time, int speed=127)
{
	motor[left]=speed;
	motor[right]=-speed;
	wait1Msec(time);
	motor[left]=0;
	motor[right]=0;
}

task autonomous()
{
	go_front(1000);
	go_back (700);
	turn(1000);
	go_front(300);
	turn(-500);
	go_front(400);
}



task usercontrol()
{

  while (true)
  {
		motor[left] = vexRT[Ch3];
		motor[right] = vexRT[Ch2];
		if(vexRT[Btn6U]==1)
		{
			motor[scissorL1] = 127;
			motor[scissorL2] = 127;
			motor[scissorR1] = 127;
			motor[scissorR2] = 127;
		}
		else if(vexRT[Btn6D]==1)
		{
			motor[scissorL1] = -127;
			motor[scissorL2] = -127;
			motor[scissorR1] = -127;
			motor[scissorR2] = -127;
		}
		else
		{
			motor[scissorL1] = 0;
			motor[scissorL2] = 0;
			motor[scissorR1] = 0;
			motor[scissorR2] = 0;
		}
		if(mobile1-10>mobile2)
		{
			motor[mobileL] = 127;
		}
		else if(mobile1+10<mobile2)
		{
			motor[mobileR] = 127;
		}
		else
		{
			if(vexRT[Btn5U]==1)
			{
				motor[mobileL] = 127;
				motor[mobileR] = 127;
			}
			else if(vexRT[Btn5D]==1)
			{
				motor[mobileL] = -127;
				motor[mobileR] = -127;
			}
			else
			{
				motor[mobileL] = 0;
				motor[mobileR] = 0;
			}
		}
  }
}
