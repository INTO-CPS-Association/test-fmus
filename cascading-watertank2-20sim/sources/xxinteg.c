/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 *
 *  file:  src\xxinteg.c
 *  subm:  CascadeWatertank2
 *  model: WaterTankCascade
 *  expmt: WaterTankCascade
 *  date:  October 30, 2015
 *  time:  12:29:28 pm
 *  user:  INTO-CPS
 *  from:  20-sim 4.5 Professional Single
 *  build: 4.5.1.5561
 **********************************************************/

/* This file describes the integration methods
   that are supplied for computation.

   Currently only Euler, RungeKutta2 and RungeKutta4 are supplied,
   but it is easy for the user to add their own
   integration methods with these two as an example.
*/

/* the system include files */
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* our own include files */
#include "xxinteg.h"
#include "xxmodel.h"

/* global variables prototypes */
extern XXDouble xx_time;
extern XXDouble xx_step_size;

#define xx_STATE_SIZE 2

#ifdef Discrete_METHOD
/*********************************************************************
 * Discrete integration method
 *********************************************************************/

/* the initialization of the Discrete integration method */
void XXDiscreteInitialize (void)
{
	/* nothing to be done */
	xx_major = XXTRUE;
}

/* the termination of the Discrete integration method */
void XXDiscreteTerminate (void)
{
	/* nothing to be done */
}

/* the Discrete integration method itself */
void XXDiscreteStep (void)
{
	XXInteger index;

	/* for each of the supplied states */
	for (index = 0; index < xx_STATE_SIZE; index++)
	{
		/* just a move of the new state */
		xx_s [index] = xx_R [index];
	}
	/* increment the simulation time */
	xx_time += xx_step_size;

	xx_major = XXTRUE;

	/* evaluate the dynamic part to calculate the new rates */
	XXCalculateDynamic ();
}
#endif /* Discrete_METHOD */


#ifdef Euler_METHOD
/*********************************************************************
 * Euler integration method
 *********************************************************************/

/* the initialization of the Euler integration method */
void XXEulerInitialize (void)
{
	/* nothing to be done */
	xx_major = XXTRUE;
}

/* the termination of the Euler integration method */
void XXEulerTerminate (void)
{
	/* nothing to be done */
}

/* the Euler integration method itself */
void XXEulerStep (void)
{
	XXInteger index;

	/* for each of the supplied states */
	for (index = 0; index < xx_STATE_SIZE; index++)
	{
		/* calculate the new state */
		xx_s [index] = xx_s [index] + xx_R [index] * xx_step_size;
	}
	/* increment the simulation time */
	xx_time += xx_step_size;

	xx_major = XXTRUE;

	/* evaluate the dynamic part to calculate the new rates */
	XXCalculateDynamic ();
}
#endif /* Euler_METHOD */


#ifdef RungeKutta2_METHOD
/*********************************************************************
 * RungeKutta2 integration method
 *********************************************************************/
/* static variables for the selected integration method */
static XXDouble xx_q0 [xx_STATE_SIZE];

/* the initialization of the RungeKutta2 integration method */
void XXRungeKutta2Initialize (void)
{
	/* empty our static arrays */
	memset (xx_q0, 0, xx_STATE_SIZE * sizeof (XXDouble));
}

/* the termination of the RungeKutta2 integration method */
void XXRungeKutta2Terminate (void)
{
	/* nothing yet (our arrays are static) */
}


/* the Runge-Kutta-2 integration method itself */
void XXRungeKutta2Step (void)
{
	XXInteger index;
	XXDouble rktime;

	/* This model has 2 states */
	/*********************************************************************************/
	/*          calculate intermediate result                                        */
	/*********************************************************************************/

	/* cache the simulation time */
	rktime = xx_time;

	/* the q0 will hold the value of the last evaluation. This is used multiple times
	   so remember the complete state array in this vector. */
	memcpy (xx_q0, xx_s, xx_STATE_SIZE * sizeof (XXDouble));

	/* calculate f (states, t) * 1/2 * dt  =  rates * 1/2 * dt  */
	for (index = 0; index < xx_STATE_SIZE; index++)
	{
		/* set the new states to use */
		xx_s [index] = xx_q0 [index] + xx_R [index] * 0.5 * xx_step_size;
	}

	xx_time = rktime + 0.5 * xx_step_size;
	xx_major = XXFALSE;
	XXCalculateDynamic ();

	/* for each state */
	for (index = 0; index < xx_STATE_SIZE; index++)
	{
		/*********************************************************************************/
		/*          calculate the next state from the intermediate results               */
		/*********************************************************************************/

		/* calculate the next state = classical Runge-Kutta integration step */
		xx_s [index] = xx_q0 [index] +	xx_R [index] * xx_step_size;
	}
	xx_time = rktime + xx_step_size;

	xx_major = XXTRUE;

	/* evaluate the derivative model to calculate the new rates */
	XXCalculateDynamic ();
}
#endif /* RungeKutta2_METHOD */


#ifdef RungeKutta4_METHOD
/*********************************************************************
 * RungeKutta4 integration method
 *********************************************************************/
/* static variables for the selected integration method */
static XXDouble xx_q0 [xx_STATE_SIZE];
static XXDouble xx_q1 [xx_STATE_SIZE];
static XXDouble xx_q2 [xx_STATE_SIZE];
static XXDouble xx_q3 [xx_STATE_SIZE];
static XXDouble xx_q4 [xx_STATE_SIZE];

/*********************************************************************
 * the initialization of the RungeKutta4 integration method
 */
void XXRungeKutta4Initialize (void)
{
	/* empty our static arrays */
	memset (xx_q0, 0, xx_STATE_SIZE * sizeof (XXDouble));
	memset (xx_q1, 0, xx_STATE_SIZE * sizeof (XXDouble));
	memset (xx_q2, 0, xx_STATE_SIZE * sizeof (XXDouble));
	memset (xx_q3, 0, xx_STATE_SIZE * sizeof (XXDouble));
	memset (xx_q4, 0, xx_STATE_SIZE * sizeof (XXDouble));
}

/* the termination of the RungeKutta4 integration method */
void XXRungeKutta4Terminate (void)
{
	/* nothing yet (our arrays are static) */
}


/* the Runge-Kutta-4 integration method itself */
void XXRungeKutta4Step (void)
{
	XXInteger index;
	XXDouble rktime;

	/* This model has 2 states */
	/*********************************************************************************/
	/*          calculate intermediate state results q1, q2, q3 and q4               */
	/*********************************************************************************/

	/* cache the simulation time */
	rktime = xx_time;

	/* the q0 will hold the value of the last evaluation. This is used multiple times
	   so remember the complete state array in this vector. */
	memcpy (xx_q0, xx_s, xx_STATE_SIZE * sizeof (XXDouble));

	/* calculate q1 = f (states, t) * dt  =  rates * dt  */
	for (index = 0; index < xx_STATE_SIZE; index++)
	{
		/* set the intermediate q1 */
		xx_q1 [index] = xx_R [index] * xx_step_size;

		/* set the new states to use  for q2 */
		xx_s [index] = xx_q0 [index] + xx_q1 [index] / 2;
	}

	/* calculate q2 = f (states + q1 / 2, t + dt / 2) * dt  */
	xx_time = rktime + xx_step_size / 2;

	xx_major = XXFALSE;

	XXCalculateDynamic ();
	memcpy (xx_q2, xx_R, xx_STATE_SIZE * sizeof (XXDouble));

	/* for each state */
	for (index = 0; index < xx_STATE_SIZE; index++)
	{
		/* set the ultimate q2 */
		xx_q2 [index] = xx_q2 [index] * xx_step_size;

		/* set the new states to use */
		xx_s [index] = xx_q0 [index] + xx_q2 [index] / 2;
	}

	/* calculate q3 = f (states + q2 / 2, t + dt / 2) * dt  */
	XXCalculateDynamic ();
	memcpy (xx_q3, xx_R, xx_STATE_SIZE * sizeof (XXDouble));

	/* for each state */
	for (index = 0; index < xx_STATE_SIZE; index++)
	{
		/* set the ultimate q3 */
		xx_q3 [index] = xx_q3 [index] * xx_step_size;

		/* set the new states */
		xx_s [index] = xx_q0 [index] + xx_q3 [index];
	}

	/* calculate q4 = f (states + q3, t + dt) * dt */
	xx_time = rktime + xx_step_size;
	XXCalculateDynamic ();
	memcpy (xx_q4, xx_R, xx_STATE_SIZE * sizeof (XXDouble));

	/* for each state */
	for (index = 0; index < xx_STATE_SIZE; index++)
	{
		/* set the ultimate q4 */
		xx_q4 [index] = xx_q4 [index] * xx_step_size;

		/*********************************************************************************/
		/*          calculate the next state from the intermediate results               */
		/*********************************************************************************/

		/* calculate the next state = classical Runge-Kutta integration step */
		xx_s [index] = xx_q0 [index] +
		xx_q1 [index] / 6 + xx_q2 [index] / 3 + xx_q3 [index] / 3 + xx_q4 [index] / 6;
	}

	xx_major = XXTRUE;

	/* evaluate the derivative model to calculate the new rates */
	XXCalculateDynamic ();
}
#endif /* RungeKutta4_METHOD */

