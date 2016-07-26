/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 *
 *  file:  src\xxsubmod.c
 *  subm:  Integrate
 *  model: Sinus Integrator Model
 *  expmt: Sinus Integrator Model
 *  date:  September 22, 2015
 *  time:  9:16:45 am
 *  user:  INTO-CPS
 *  from:  20-sim 4.5 Professional Single
 *  build: 4.5.1.5561
 **********************************************************/

/* Standard include files */
#include <stdlib.h>

/* 20-sim include files */
#include "xxmodel.h"
#include "xxinteg.h"
#include "xxfuncs.h"
#include "xxsubmod.h"
#include "motionprofiles.h"
#include "EulerAngles.h"


/* The initialization function for submodel */
void XXInitializeSubmodel (XXDouble t)
{
	/* Initialization phase (allocating memory) */
	xx_initialize = XXTRUE;
	xx_steps = 0;
	XXModelInitialize ();
	XXRungeKutta4Initialize ();

	/* Copy the time */
	xx_time = t;

	/* Calculate the model for the first time */
	XXCalculateInitial ();
	XXCalculateStatic ();
	XXCalculateInput ();
	XXCalculateDynamic ();
	XXCalculateOutput ();

	/* End of initialization phase */
	xx_initialize = XXFALSE;
}

/* The function that calculates the submodel */
void XXCalculateSubmodel (XXDouble t)
{
	/* Copy the time */
	xx_time = t;

	/* Calculate the model */
	XXCalculateInput ();
	XXRungeKutta4Step ();
	XXCalculateOutput ();
}

/* The termination function for submodel */
void XXTerminateSubmodel (XXDouble t)
{
	/* Copy the time */
	xx_time = t;

	/* Calculate the final model equations */
	XXCalculateFinal ();

	/* and terminate the model itself (releasing memory) */
	XXModelTerminate ();
	XXRungeKutta4Terminate ();
}
