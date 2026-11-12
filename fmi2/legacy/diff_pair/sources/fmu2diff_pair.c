/* ---------------------------------------------------------------------------*
 * Sample implementation of an FMU - the Dahlquist test equation.
 *
 *   der(x) = - k * x and x(0) = 1. 
 *   Analytical solution: x(t) = exp(-k*t).
 * Copyright QTronic GmbH. All rights reserved.
 * ---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
// define class name and unique id
#define MODEL_IDENTIFIER diff_pair
#define MODEL_GUID "{fa050d5c-11e5-4b3c-a861-ba9adaed4473}"

// define model size
#define NUMBER_OF_REALS 100
#define NUMBER_OF_INTEGERS 100
#define NUMBER_OF_BOOLEANS 100
#define NUMBER_OF_STRINGS 100
#define NUMBER_OF_STATES 1
#define NUMBER_OF_EVENT_INDICATORS 0

// include fmu header files, typedefs and macros
#include "template/fmuTemplate.h"


// define all model variables and their value references
// conventions used here:
// - if x is a variable, then macro x_ is its variable reference
// - the vr of a variable is its index in array  r, i, b or s
// - if k is the vr of a real state, then k+1 is the vr of its derivative
#define x_     0
#define der_x_ 1
#define k_     2

// define state vector as vector of value references
#define STATES { x_ }

// called by fmi2Instantiate
// Set values for all variables that define a start value
// Settings used unless changed by fmi2SetX before fmi2EnterInitializationMode
void setStartValues(ModelInstance *comp) {
    r(x_) = 1;
    r(k_) = 1;
}

// called by fmi2GetReal, fmi2GetInteger, fmi2GetBoolean, fmi2GetString, fmi2ExitInitialization
// if setStartValues or environment set new values through fmi2SetXXX.
// Lazy set values for all variable that are computed from other variables.
void calculateValues(ModelInstance *comp) {
    //if (comp->state == modelInitializationMode) {
    //  initialization code here
    //  set first time event, if any, using comp->eventInfo.nextEventTime
    //}
}

// called by fmi2GetReal, fmi2GetContinuousStates and fmi2GetDerivatives
fmi2Real getReal(ModelInstance* comp, fmi2ValueReference vr){
    switch (vr) {
        case x_     : return r(x_);
        case der_x_ : return - r(k_) * r(x_);
        case k_     : return r(k_);
        default: return 0;
    }
}

// used to set the next time event, if any.
void eventUpdate(ModelInstance *comp, fmi2EventInfo *eventInfo, int isTimeEvent) {
} 


#define out_r_diff 1
#define out_i_diff 2
#define out_b_diff 3
#define out_s_diff 4
#define in_r_a 5
#define in_r_b 6
#define in_i_a 7
#define in_i_b 8
#define in_b_a 9
#define in_b_b 10
#define in_s_a 11
#define in_s_b 12


fmi2Status fmi2DoStepInternal(ModelInstance *comp, fmi2Real currentCommunicationPoint,
	fmi2Real communicationStepSize, fmi2Boolean noSetFMUStatePriorToCurrentPoint){
	//printf("\tinternal step level\n");

    comp->r[out_r_diff]=abs(comp->r[in_r_a]-comp->r[in_r_b]);
    comp->i[out_i_diff]=abs(comp->i[in_i_a]-comp->i[in_i_b]);
    comp->b[out_r_diff]=comp->b[in_b_a]&&comp->b[in_b_b];
    if(comp->s[in_s_a]==0 || comp->s[in_s_b]==0)
    {
        comp->s[out_s_diff]="unknown";
    }else
    {
        comp->s[out_s_diff]=strcmp(comp->s[in_s_a],comp->s[in_s_b])?"equal":"different";       
    }


	return fmi2OK;
}

// include code that implements the FMI based on the above definitions
#include "template/fmuTemplate.c"


