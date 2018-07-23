#pragma config(Sensor, in1,    liftPot,        sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,           sensorGyro)
#pragma config(Sensor, in3,    selector,       sensorPotentiometer)
#pragma config(Sensor, in4,    fourPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           descorer,      tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           puncher1,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightBack,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           intake,        tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           rightFront,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftFront,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           leftBack,      tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           puncher2,      tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"
//-----------------------------------------------------------------------------

//Tasks/Functions/Gyro section

void BasicDrive(int left, int right, int revs)
{
	SensorValue[leftEncoder] = 0;

	while(abs(SensorValue[leftEncoder]) < revs)
	{
		if(abs(SensorValue[leftEncoder]) <= revs)
		{
			motor(rightBack) = motor(rightFront) = right;
			motor(leftBack) = motor(leftFront) = left;
		}
		else
		{
			motor(rightBack) = motor(rightFront) = 0;
			motor(leftBack) = motor(leftFront) = 0;
		}
	}
	motor(rightBack) = motor(rightFront) = 0;
	motor(leftBack) = motor(leftFront) = 0;
}


void turn(int left, int right, int degrees10)
{
	SensorValue[gyro] = 0;
	while(abs(SensorValue[in2]) < degrees10 - 10)
	{
		motor(leftBack) = motor(leftFront) = left;
		motor(rightBack) = motor(rightFront) = right;
	}
	//Brief brake to eliminate some drift
	if (left > 0)
	{
		motor[rightFront] = motor(rightBack) = -5;
		motor[leftFront] = motor(leftBack) = 5;
		wait1Msec(100);
	}
	else
	{
		motor[rightFront] = motor(rightBack) = 5;
		motor[leftFront] = motor(leftBack) = -5;
		wait1Msec(100);
	}
	//Stop
	motor[rightFront] = motor(rightBack) = 0;
	motor[leftFront] = motor(leftBack) = 0;
	wait1Msec(250);
}

//int error;


void LoopyMove (int power, int setpoint)
{
	SensorValue[leftEncoder] = 0;
	int kP = 0.5;
	while(abs(SensorValue[leftEncoder]) < setpoint)
	{
		motor(leftBack) = motor(leftFront) = (setpoint - SensorValue[leftEncoder]) * kP;
		motor(rightFront) = motor(rightFront) = (setpoint - SensorValue[rightEncoder]) * kP;
	}
	motor(rightBack) = motor(rightFront) = 0;
	motor(leftBack) = motor(leftFront) = 0;
}

int autoNumber;


task progselect()
{
	while (true)
	{
		if (SensorValue[selector] < 400)
		{
			autoNumber = 1;
		}
		else if (SensorValue[selector] < 1150 && SensorValue[selector] > 400)
		{
			autoNumber = 2;
		}
		else if (SensorValue[selector] < 1550 && SensorValue[selector] > 1150)
		{
			autoNumber = 3;
		}
		else if (SensorValue[selector] < 2000 && SensorValue[selector] > 1550)
		{
			autoNumber = 4;
		}
		else if (SensorValue[selector] < 2500 && SensorValue[selector] > 2000)
		{
			autoNumber = 5;
		}
		else if (SensorValue[selector] < 3000 && SensorValue[selector] > 2500)
		{
			autoNumber = 6;
		}
		else if (SensorValue[selector] < 3500 && SensorValue[selector] > 3000)
		{
			autoNumber = 7;
		}
		else
		{
			autoNumber = 8;
		}


		// give up the CPU, even though we may have
		// nothing else running in pre-autonomous
		wait1Msec(10);

		if (autoNumber == 1)
		{
			displayLCDCenteredString(0, "Auton Selected: ");
			displayLCDCenteredString(1, "Red Close/Super");
			wait1Msec(100);
		}
		else if (autoNumber == 2)
		{
			displayLCDCenteredString(0, "Auton Selected: ");
			displayLCDCenteredString(1, "Red Far");
			wait1Msec(100);
		}
		else if (autoNumber == 3)
		{
			displayLCDCenteredString(0, "Auton Selected: ");
			displayLCDCenteredString(1, "Blue Close/Super");
			wait1Msec(100);
		}
		else if (autoNumber == 4)
		{
			displayLCDCenteredString(0, "Auton Selected: ");
			displayLCDCenteredString(1, "Blue Far");
			wait1Msec(100);
		}
		else if (autoNumber == 5)
		{
			displayLCDCenteredString(0, "Auton Selected: ");
			displayLCDCenteredString(1, "3 Cone Block R");
			wait1Msec(100);
		}
		else if (autoNumber == 6)
		{
			displayLCDCenteredString(0, "Auton Selected: ");
			displayLCDCenteredString(1, "3 Cone Block L");
			wait1Msec(100);
		}
		else if (autoNumber == 7)
		{
			displayLCDCenteredString(0, "Auton Selected: ");
			displayLCDCenteredString(1, "Sationary");
			wait1Msec(100);
		}
		else if(autoNumber == 8)
		{
			displayLCDCenteredString(0, "Auton Selected: ");
			displayLCDCenteredString(1, "Mogo Hoard");
			wait1Msec(100);
		}
		else
		{
			wait1Msec(10);
		}
	}
}


void pre_auton()
{

	startTask(progselect);
	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
	SensorType[in2] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Analog Port 2 as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[in2] = sensorGyro;
	wait1Msec(2000);



	bDisplayCompetitionStatusOnLcd = false;
	bLCDBacklight = true;
	clearLCDLine(0);                                            // Clear line 1 (0) of the LCD
	clearLCDLine(1);                                            // Clear line 2 (1) of the LCD




	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.




}

task autonomous()
{


	/*
	stackheight = 2000;
	startTask(stacker);
	wait1Msec(2500);
	stopTask(stacker);
	stopTask(liftdown);
	motor(leftLift) = motor(rightLift) = 0;
	wait1Msec(2000);
	stackheight = 1900;
	startTask(stacker);
	wait1Msec(2500);
	stopTask(stacker);
	stopTask(liftdown);
	motor(leftLift) = motor(rightLift) = 0;
	*/
	stopTask(progselect);
	displayLCDCenteredString(0, "Starting Auton: ");
		if (autoNumber == 1) //red close/super
	{
		//drive to tilted cap
		//take ball from tilted cap
		//drive back to wall
		//turn to line up
		//forward and shoot
		//forward and shoot
		//slight turn
		//low flag bop

	}
	else if (autoNumber == 2) //red far
	{
		//shoot preload
		//turn and line up
		//drive to tiled cap
		//take the ball
		//back up
		//line up on platform
		//park
	}
	else if (autoNumber == 3) //blue close/super
	{
		//drive to tilted cap
		//take ball from tilted cap
		//drive back to wall
		//turn to line up
		//forward and shoot
		//forward and shoot
		//slight turn
		//low flag bop
	}
	else if (autoNumber == 4) //blue far
	{
		//shoot preload
		//turn and line up
		//drive to tiled cap
		//take the ball
		//back up
		//line up on platform
		//park
	}
	else
	{
	wait1Msec(10);
	}


}
task usercontrol()
{


	while (true)
	{

		int deadthresh = +-20;

		motor[leftFront] = vexRT[Ch3] + vexRT[Ch1];
		motor[leftBack] = vexRT[Ch3] + vexRT[Ch1];
		motor[rightFront] = vexRT[Ch3] - vexRT[Ch1];
		motor[rightBack] = vexRT[Ch3] - vexRT[Ch1];


		//launcher buttons
		if((vexRT[Btn5U] == 1))
		{
			motor(puncher1) = 127;
			motor(puncher2) = 127;
		}
		else
		{
			motor[puncher1] = 0;
			motor[puncher2] = 0;
		}
		//--------------------------------------------------------------------------------
		//Descorer Buttons
		if (vexRT[Btn6U] == 1)
		{
			motor(descorer) = -127;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor(descorer) = 127;
		}
		else
		{
			motor(descorer) = 0;
		}






		//---------------------------------------------------------------------------------
		//Intake Buttons
		if (vexRT[Btn5D] == 1)
		{
			motor(intake) = 127;
		}
		else if(vexRT[Btn8U] == 1)
		{
			motor(intake) = -127;
		}
		else
		{
			motor(intake) = 0;
		}
	}
}	//these are the end
