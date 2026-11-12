
// define class name and unique id
#define MODEL_IDENTIFIER LineFollower_Examples_SensorBlock2
#define MODEL_GUID "{bb5eedb0-8d6b-4a9c-9b34-2d7584c3293e}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "LineFollower_Examples_SensorBlock2_functions.h"
#include "simulation/solver/initialization/initialization.h"
#include "simulation/solver/events.h"
#include "fmu2_model_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

void setStartValues(ModelInstance *comp);
void setDefaultStartValues(ModelInstance *comp);
void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo);
fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value);
fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value);
fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value);
fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr);
fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value);
fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value);

// define model size
#define NUMBER_OF_STATES 0
#define NUMBER_OF_EVENT_INDICATORS 6
#define NUMBER_OF_REALS 57
#define NUMBER_OF_INTEGERS 2
#define NUMBER_OF_STRINGS 3
#define NUMBER_OF_BOOLEANS 2
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define variable data for model
#define $Plf_1_sensor_reading_vr 0 
#define $Probot_theta_vr 1 
#define $Probot_x_vr 2 
#define $Probot_y_vr 3 
#define $Probot_z_vr 4 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Phalf_lsb_vr 5 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Phold_signal_vr 6 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Plsb_vr 7 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_vr 8 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pquantisized_signal_vr 9 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pwindowed_signal_vr 10 
#define $Psensor1$Pad_8bit1$Pi_vr 11 
#define $Psensor1$Pambient_light1$Pi_vr 12 
#define $Psensor1$Pambient_light1$Po_vr 13 
#define $Psensor1$Pambient_light1$Preflected_power_vr 14 
#define $Psensor1$Pcalculate_sensor_position1$Protated_x_vr 15 
#define $Psensor1$Pcalculate_sensor_position1$Protated_y_vr 16 
#define $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB1$rB_vr 17 
#define $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB2$rB_vr 18 
#define $Psensor1$Pcombitable2d1$Py_vr 19 // "Connector of Real output signal"
#define $Plf_position_x_vr 20 
#define $Plf_position_y_vr 21 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$PbitPower_vr 22 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pbits_vr 23 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pmaximum_vr 24 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pminimum_vr 25 
#define $Psensor1$Pambient_light1$Pambient_light_vr 26 
#define $Psensor1$Pambient_light1$Pled_power_vr 27 
#define $Psensor1$Pambient_light1$Prx_power_off_vr 28 
#define $Psensor1$Pambient_light1$Prx_power_on_vr 29 
#define $Psensor1$Pcalculate_sensor_position1$Plf_positions$lB1$rB_vr 30 
#define $Psensor1$Pcalculate_sensor_position1$Plf_positions$lB2$rB_vr 31 
#define $Psensor1$Pcombitable2d1$PtableOnFileRead_vr 32 // "= 1, if table was successfully read from file"
#define $Psensor1$Ppercentageto8bitvalue1$Pk_vr 33 
#define $Psensor1$Praw_to_reflectivity1$Phi_input_vr 34 
#define $Psensor1$Praw_to_reflectivity1$Phi_output_vr 35 
#define $Psensor1$Praw_to_reflectivity1$Plo_input_vr 36 
#define $Psensor1$Praw_to_reflectivity1$Plo_output_vr 37 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pi_vr 38 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_value_vr 39 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Po_vr 40 
#define $Psensor1$Pad_8bit1$Po_vr 41 
#define $Psensor1$Pcalculate_sensor_position1$Probot_state$lB1$rB_vr 42 
#define $Psensor1$Pcalculate_sensor_position1$Probot_state$lB2$rB_vr 43 
#define $Psensor1$Pcalculate_sensor_position1$Probot_state$lB3$rB_vr 44 
#define $Psensor1$Pcalculate_sensor_position1$Probot_state$lB4$rB_vr 45 
#define $Psensor1$Pcombitable2d1$Pu1_vr 46 // "Connector of Real input signal 1"
#define $Psensor1$Pcombitable2d1$Pu2_vr 47 // "Connector of Real input signal 2"
#define $Psensor1$Ppercentageto8bitvalue1$Pi_vr 48 
#define $Psensor1$Ppercentageto8bitvalue1$Po_vr 49 
#define $Psensor1$Praw_to_reflectivity1$Praw_map_reading_vr 50 
#define $Psensor1$Praw_to_reflectivity1$Preflectivity_vr 51 
#define $Psensor1$Probot_state$lB1$rB_vr 52 
#define $Psensor1$Probot_state$lB2$rB_vr 53 
#define $Psensor1$Probot_state$lB3$rB_vr 54 
#define $Psensor1$Probot_state$lB4$rB_vr 55 
#define $Psensor1$Psensor_output_vr 56 
#define $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_level_vr 0 
#define $Psensor1$Pcombitable2d1$Psmoothness_vr 1 // "Smoothness of table interpolation"
#define $Psensor1$Pcombitable2d1$PtableOnFile_vr 0 // "= true, if table is defined on file or in function usertab"
#define $Psensor1$Pcombitable2d1$PverboseRead_vr 1 // "= true, if info message that file is loading is to be printed"
#define $Psensor1$Pcombitable2d1$PfileName_vr 0 // "File where matrix is stored"
#define $Psensor1$Pcombitable2d1$PtableName_vr 1 // "Table name on file or in function usertab (see docu)"
#define $Psensor1$PfileNameMapTable_vr 2 // "File with map data"


// define initial state vector as vector of value references
#define STATES {  }
#define STATESDERIVATIVES {  }


// implementation of the Model Exchange functions
  extern void LineFollower_Examples_SensorBlock2_setupDataStruc(DATA *data);
  #define fmu2_model_interface_setupDataStruc LineFollower_Examples_SensorBlock2_setupDataStruc
  #include "fmu2_model_interface.c"

// Set values for all variables that define a start value
void setDefaultStartValues(ModelInstance *comp) {

comp->fmuData->modelData->realVarsData[0].attribute.start = 0;
comp->fmuData->modelData->realVarsData[1].attribute.start = 0;
comp->fmuData->modelData->realVarsData[2].attribute.start = 0;
comp->fmuData->modelData->realVarsData[3].attribute.start = 0;
comp->fmuData->modelData->realVarsData[4].attribute.start = 0;
comp->fmuData->modelData->realVarsData[5].attribute.start = 0;
comp->fmuData->modelData->realVarsData[6].attribute.start = 0;
comp->fmuData->modelData->realVarsData[7].attribute.start = 0;
comp->fmuData->modelData->realVarsData[8].attribute.start = 0;
comp->fmuData->modelData->realVarsData[9].attribute.start = 0;
comp->fmuData->modelData->realVarsData[10].attribute.start = 0;
comp->fmuData->modelData->realVarsData[11].attribute.start = 0;
comp->fmuData->modelData->realVarsData[12].attribute.start = 0;
comp->fmuData->modelData->realVarsData[13].attribute.start = 0;
comp->fmuData->modelData->realVarsData[14].attribute.start = 0;
comp->fmuData->modelData->realVarsData[15].attribute.start = 0;
comp->fmuData->modelData->realVarsData[16].attribute.start = 0;
comp->fmuData->modelData->realVarsData[17].attribute.start = 0;
comp->fmuData->modelData->realVarsData[18].attribute.start = 0;
comp->fmuData->modelData->realVarsData[19].attribute.start = 0;
comp->fmuData->modelData->integerVarsData[0].attribute.start = 0;
comp->fmuData->modelData->realParameterData[0].attribute.start = -0.01;
comp->fmuData->modelData->realParameterData[1].attribute.start = 0.065;
comp->fmuData->modelData->realParameterData[3].attribute.start = 8.0;
comp->fmuData->modelData->realParameterData[4].attribute.start = 255.0;
comp->fmuData->modelData->realParameterData[5].attribute.start = 0.0;
comp->fmuData->modelData->realParameterData[6].attribute.start = 0.0;
comp->fmuData->modelData->realParameterData[7].attribute.start = 5.0;
comp->fmuData->modelData->realParameterData[8].attribute.start = 0.5;
comp->fmuData->modelData->realParameterData[9].attribute.start = 4.5;
comp->fmuData->modelData->realParameterData[13].attribute.start = 255.0;
comp->fmuData->modelData->realParameterData[14].attribute.start = -1.0;
comp->fmuData->modelData->realParameterData[15].attribute.start = 0.9;
comp->fmuData->modelData->realParameterData[16].attribute.start = -16777216.0;
comp->fmuData->modelData->realParameterData[17].attribute.start = 0.1;
comp->fmuData->modelData->integerParameterData[0].attribute.start = 1;
comp->fmuData->modelData->booleanParameterData[0].attribute.start = 1;
comp->fmuData->modelData->booleanParameterData[1].attribute.start = 1;
comp->fmuData->modelData->stringParameterData[1].attribute.start = "map";
}
// Set values for all variables that define a start value
void setStartValues(ModelInstance *comp) {

  comp->fmuData->modelData->realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData->realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData->realVarsData[2].attribute.start =  comp->fmuData->localData[0]->realVars[2];
  comp->fmuData->modelData->realVarsData[3].attribute.start =  comp->fmuData->localData[0]->realVars[3];
  comp->fmuData->modelData->realVarsData[4].attribute.start =  comp->fmuData->localData[0]->realVars[4];
  comp->fmuData->modelData->realVarsData[5].attribute.start =  comp->fmuData->localData[0]->realVars[5];
  comp->fmuData->modelData->realVarsData[6].attribute.start =  comp->fmuData->localData[0]->realVars[6];
  comp->fmuData->modelData->realVarsData[7].attribute.start =  comp->fmuData->localData[0]->realVars[7];
  comp->fmuData->modelData->realVarsData[8].attribute.start =  comp->fmuData->localData[0]->realVars[8];
  comp->fmuData->modelData->realVarsData[9].attribute.start =  comp->fmuData->localData[0]->realVars[9];
  comp->fmuData->modelData->realVarsData[10].attribute.start =  comp->fmuData->localData[0]->realVars[10];
  comp->fmuData->modelData->realVarsData[11].attribute.start =  comp->fmuData->localData[0]->realVars[11];
  comp->fmuData->modelData->realVarsData[12].attribute.start =  comp->fmuData->localData[0]->realVars[12];
  comp->fmuData->modelData->realVarsData[13].attribute.start =  comp->fmuData->localData[0]->realVars[13];
  comp->fmuData->modelData->realVarsData[14].attribute.start =  comp->fmuData->localData[0]->realVars[14];
  comp->fmuData->modelData->realVarsData[15].attribute.start =  comp->fmuData->localData[0]->realVars[15];
  comp->fmuData->modelData->realVarsData[16].attribute.start =  comp->fmuData->localData[0]->realVars[16];
  comp->fmuData->modelData->realVarsData[17].attribute.start =  comp->fmuData->localData[0]->realVars[17];
  comp->fmuData->modelData->realVarsData[18].attribute.start =  comp->fmuData->localData[0]->realVars[18];
  comp->fmuData->modelData->realVarsData[19].attribute.start =  comp->fmuData->localData[0]->realVars[19];
  comp->fmuData->modelData->integerVarsData[0].attribute.start =  comp->fmuData->localData[0]->integerVars[0];
comp->fmuData->modelData->realParameterData[0].attribute.start = comp->fmuData->simulationInfo->realParameter[0];
comp->fmuData->modelData->realParameterData[1].attribute.start = comp->fmuData->simulationInfo->realParameter[1];
comp->fmuData->modelData->realParameterData[2].attribute.start = comp->fmuData->simulationInfo->realParameter[2];
comp->fmuData->modelData->realParameterData[3].attribute.start = comp->fmuData->simulationInfo->realParameter[3];
comp->fmuData->modelData->realParameterData[4].attribute.start = comp->fmuData->simulationInfo->realParameter[4];
comp->fmuData->modelData->realParameterData[5].attribute.start = comp->fmuData->simulationInfo->realParameter[5];
comp->fmuData->modelData->realParameterData[6].attribute.start = comp->fmuData->simulationInfo->realParameter[6];
comp->fmuData->modelData->realParameterData[7].attribute.start = comp->fmuData->simulationInfo->realParameter[7];
comp->fmuData->modelData->realParameterData[8].attribute.start = comp->fmuData->simulationInfo->realParameter[8];
comp->fmuData->modelData->realParameterData[9].attribute.start = comp->fmuData->simulationInfo->realParameter[9];
comp->fmuData->modelData->realParameterData[10].attribute.start = comp->fmuData->simulationInfo->realParameter[10];
comp->fmuData->modelData->realParameterData[11].attribute.start = comp->fmuData->simulationInfo->realParameter[11];
comp->fmuData->modelData->realParameterData[12].attribute.start = comp->fmuData->simulationInfo->realParameter[12];
comp->fmuData->modelData->realParameterData[13].attribute.start = comp->fmuData->simulationInfo->realParameter[13];
comp->fmuData->modelData->realParameterData[14].attribute.start = comp->fmuData->simulationInfo->realParameter[14];
comp->fmuData->modelData->realParameterData[15].attribute.start = comp->fmuData->simulationInfo->realParameter[15];
comp->fmuData->modelData->realParameterData[16].attribute.start = comp->fmuData->simulationInfo->realParameter[16];
comp->fmuData->modelData->realParameterData[17].attribute.start = comp->fmuData->simulationInfo->realParameter[17];
comp->fmuData->modelData->integerParameterData[0].attribute.start = comp->fmuData->simulationInfo->integerParameter[0];
comp->fmuData->modelData->booleanParameterData[0].attribute.start = comp->fmuData->simulationInfo->booleanParameter[0];
comp->fmuData->modelData->booleanParameterData[1].attribute.start = comp->fmuData->simulationInfo->booleanParameter[1];
comp->fmuData->modelData->stringParameterData[0].attribute.start = comp->fmuData->simulationInfo->stringParameter[0];
comp->fmuData->modelData->stringParameterData[1].attribute.start = comp->fmuData->simulationInfo->stringParameter[1];
comp->fmuData->modelData->stringParameterData[2].attribute.start = comp->fmuData->simulationInfo->stringParameter[2];
}
  // Used to set the next time event, if any.
  void eventUpdate(ModelInstance* comp, fmi2EventInfo* eventInfo) {
  }
  
  fmi2Real getReal(ModelInstance* comp, const fmi2ValueReference vr) {
    switch (vr) {
        case $Plf_1_sensor_reading_vr : return comp->fmuData->localData[0]->realVars[0]; break;
        case $Probot_theta_vr : return comp->fmuData->localData[0]->realVars[1]; break;
        case $Probot_x_vr : return comp->fmuData->localData[0]->realVars[2]; break;
        case $Probot_y_vr : return comp->fmuData->localData[0]->realVars[3]; break;
        case $Probot_z_vr : return comp->fmuData->localData[0]->realVars[4]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Phalf_lsb_vr : return comp->fmuData->localData[0]->realVars[5]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Phold_signal_vr : return comp->fmuData->localData[0]->realVars[6]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Plsb_vr : return comp->fmuData->localData[0]->realVars[7]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_vr : return comp->fmuData->localData[0]->realVars[8]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pquantisized_signal_vr : return comp->fmuData->localData[0]->realVars[9]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pwindowed_signal_vr : return comp->fmuData->localData[0]->realVars[10]; break;
        case $Psensor1$Pad_8bit1$Pi_vr : return comp->fmuData->localData[0]->realVars[11]; break;
        case $Psensor1$Pambient_light1$Pi_vr : return comp->fmuData->localData[0]->realVars[12]; break;
        case $Psensor1$Pambient_light1$Po_vr : return comp->fmuData->localData[0]->realVars[13]; break;
        case $Psensor1$Pambient_light1$Preflected_power_vr : return comp->fmuData->localData[0]->realVars[14]; break;
        case $Psensor1$Pcalculate_sensor_position1$Protated_x_vr : return comp->fmuData->localData[0]->realVars[15]; break;
        case $Psensor1$Pcalculate_sensor_position1$Protated_y_vr : return comp->fmuData->localData[0]->realVars[16]; break;
        case $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB1$rB_vr : return comp->fmuData->localData[0]->realVars[17]; break;
        case $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB2$rB_vr : return comp->fmuData->localData[0]->realVars[18]; break;
        case $Psensor1$Pcombitable2d1$Py_vr : return comp->fmuData->localData[0]->realVars[19]; break;
        case $Plf_position_x_vr : return comp->fmuData->simulationInfo->realParameter[0]; break;
        case $Plf_position_y_vr : return comp->fmuData->simulationInfo->realParameter[1]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$PbitPower_vr : return comp->fmuData->simulationInfo->realParameter[2]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pbits_vr : return comp->fmuData->simulationInfo->realParameter[3]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pmaximum_vr : return comp->fmuData->simulationInfo->realParameter[4]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pminimum_vr : return comp->fmuData->simulationInfo->realParameter[5]; break;
        case $Psensor1$Pambient_light1$Pambient_light_vr : return comp->fmuData->simulationInfo->realParameter[6]; break;
        case $Psensor1$Pambient_light1$Pled_power_vr : return comp->fmuData->simulationInfo->realParameter[7]; break;
        case $Psensor1$Pambient_light1$Prx_power_off_vr : return comp->fmuData->simulationInfo->realParameter[8]; break;
        case $Psensor1$Pambient_light1$Prx_power_on_vr : return comp->fmuData->simulationInfo->realParameter[9]; break;
        case $Psensor1$Pcalculate_sensor_position1$Plf_positions$lB1$rB_vr : return comp->fmuData->simulationInfo->realParameter[10]; break;
        case $Psensor1$Pcalculate_sensor_position1$Plf_positions$lB2$rB_vr : return comp->fmuData->simulationInfo->realParameter[11]; break;
        case $Psensor1$Pcombitable2d1$PtableOnFileRead_vr : return comp->fmuData->simulationInfo->realParameter[12]; break;
        case $Psensor1$Ppercentageto8bitvalue1$Pk_vr : return comp->fmuData->simulationInfo->realParameter[13]; break;
        case $Psensor1$Praw_to_reflectivity1$Phi_input_vr : return comp->fmuData->simulationInfo->realParameter[14]; break;
        case $Psensor1$Praw_to_reflectivity1$Phi_output_vr : return comp->fmuData->simulationInfo->realParameter[15]; break;
        case $Psensor1$Praw_to_reflectivity1$Plo_input_vr : return comp->fmuData->simulationInfo->realParameter[16]; break;
        case $Psensor1$Praw_to_reflectivity1$Plo_output_vr : return comp->fmuData->simulationInfo->realParameter[17]; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pi_vr : return getReal(comp, $Psensor1$Pad_8bit1$Pi_vr); break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_value_vr : return getReal(comp, $Psensor1$Pad_8bit1$Pad_8bitblock1$Plsb_vr); break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Po_vr : return getReal(comp, $Plf_1_sensor_reading_vr); break;
        case $Psensor1$Pad_8bit1$Po_vr : return getReal(comp, $Plf_1_sensor_reading_vr); break;
        case $Psensor1$Pcalculate_sensor_position1$Probot_state$lB1$rB_vr : return getReal(comp, $Probot_x_vr); break;
        case $Psensor1$Pcalculate_sensor_position1$Probot_state$lB2$rB_vr : return getReal(comp, $Probot_y_vr); break;
        case $Psensor1$Pcalculate_sensor_position1$Probot_state$lB3$rB_vr : return getReal(comp, $Probot_z_vr); break;
        case $Psensor1$Pcalculate_sensor_position1$Probot_state$lB4$rB_vr : return getReal(comp, $Probot_theta_vr); break;
        case $Psensor1$Pcombitable2d1$Pu1_vr : return getReal(comp, $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB2$rB_vr); break;
        case $Psensor1$Pcombitable2d1$Pu2_vr : return getReal(comp, $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB1$rB_vr); break;
        case $Psensor1$Ppercentageto8bitvalue1$Pi_vr : return getReal(comp, $Psensor1$Pambient_light1$Po_vr); break;
        case $Psensor1$Ppercentageto8bitvalue1$Po_vr : return getReal(comp, $Psensor1$Pad_8bit1$Pi_vr); break;
        case $Psensor1$Praw_to_reflectivity1$Praw_map_reading_vr : return getReal(comp, $Psensor1$Pcombitable2d1$Py_vr); break;
        case $Psensor1$Praw_to_reflectivity1$Preflectivity_vr : return getReal(comp, $Psensor1$Pambient_light1$Pi_vr); break;
        case $Psensor1$Probot_state$lB1$rB_vr : return getReal(comp, $Probot_x_vr); break;
        case $Psensor1$Probot_state$lB2$rB_vr : return getReal(comp, $Probot_y_vr); break;
        case $Psensor1$Probot_state$lB3$rB_vr : return getReal(comp, $Probot_z_vr); break;
        case $Psensor1$Probot_state$lB4$rB_vr : return getReal(comp, $Probot_theta_vr); break;
        case $Psensor1$Psensor_output_vr : return getReal(comp, $Plf_1_sensor_reading_vr); break;
        default:
            return 0;
    }
  }
  
  fmi2Status setReal(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Real value) {
    switch (vr) {
        case $Plf_1_sensor_reading_vr : comp->fmuData->localData[0]->realVars[0] = value; break;
        case $Probot_theta_vr : comp->fmuData->localData[0]->realVars[1] = value; break;
        case $Probot_x_vr : comp->fmuData->localData[0]->realVars[2] = value; break;
        case $Probot_y_vr : comp->fmuData->localData[0]->realVars[3] = value; break;
        case $Probot_z_vr : comp->fmuData->localData[0]->realVars[4] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Phalf_lsb_vr : comp->fmuData->localData[0]->realVars[5] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Phold_signal_vr : comp->fmuData->localData[0]->realVars[6] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Plsb_vr : comp->fmuData->localData[0]->realVars[7] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_vr : comp->fmuData->localData[0]->realVars[8] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pquantisized_signal_vr : comp->fmuData->localData[0]->realVars[9] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pwindowed_signal_vr : comp->fmuData->localData[0]->realVars[10] = value; break;
        case $Psensor1$Pad_8bit1$Pi_vr : comp->fmuData->localData[0]->realVars[11] = value; break;
        case $Psensor1$Pambient_light1$Pi_vr : comp->fmuData->localData[0]->realVars[12] = value; break;
        case $Psensor1$Pambient_light1$Po_vr : comp->fmuData->localData[0]->realVars[13] = value; break;
        case $Psensor1$Pambient_light1$Preflected_power_vr : comp->fmuData->localData[0]->realVars[14] = value; break;
        case $Psensor1$Pcalculate_sensor_position1$Protated_x_vr : comp->fmuData->localData[0]->realVars[15] = value; break;
        case $Psensor1$Pcalculate_sensor_position1$Protated_y_vr : comp->fmuData->localData[0]->realVars[16] = value; break;
        case $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB1$rB_vr : comp->fmuData->localData[0]->realVars[17] = value; break;
        case $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB2$rB_vr : comp->fmuData->localData[0]->realVars[18] = value; break;
        case $Psensor1$Pcombitable2d1$Py_vr : comp->fmuData->localData[0]->realVars[19] = value; break;
        case $Plf_position_x_vr : comp->fmuData->simulationInfo->realParameter[0] = value; break;
        case $Plf_position_y_vr : comp->fmuData->simulationInfo->realParameter[1] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$PbitPower_vr : comp->fmuData->simulationInfo->realParameter[2] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pbits_vr : comp->fmuData->simulationInfo->realParameter[3] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pmaximum_vr : comp->fmuData->simulationInfo->realParameter[4] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pminimum_vr : comp->fmuData->simulationInfo->realParameter[5] = value; break;
        case $Psensor1$Pambient_light1$Pambient_light_vr : comp->fmuData->simulationInfo->realParameter[6] = value; break;
        case $Psensor1$Pambient_light1$Pled_power_vr : comp->fmuData->simulationInfo->realParameter[7] = value; break;
        case $Psensor1$Pambient_light1$Prx_power_off_vr : comp->fmuData->simulationInfo->realParameter[8] = value; break;
        case $Psensor1$Pambient_light1$Prx_power_on_vr : comp->fmuData->simulationInfo->realParameter[9] = value; break;
        case $Psensor1$Pcalculate_sensor_position1$Plf_positions$lB1$rB_vr : comp->fmuData->simulationInfo->realParameter[10] = value; break;
        case $Psensor1$Pcalculate_sensor_position1$Plf_positions$lB2$rB_vr : comp->fmuData->simulationInfo->realParameter[11] = value; break;
        case $Psensor1$Pcombitable2d1$PtableOnFileRead_vr : comp->fmuData->simulationInfo->realParameter[12] = value; break;
        case $Psensor1$Ppercentageto8bitvalue1$Pk_vr : comp->fmuData->simulationInfo->realParameter[13] = value; break;
        case $Psensor1$Praw_to_reflectivity1$Phi_input_vr : comp->fmuData->simulationInfo->realParameter[14] = value; break;
        case $Psensor1$Praw_to_reflectivity1$Phi_output_vr : comp->fmuData->simulationInfo->realParameter[15] = value; break;
        case $Psensor1$Praw_to_reflectivity1$Plo_input_vr : comp->fmuData->simulationInfo->realParameter[16] = value; break;
        case $Psensor1$Praw_to_reflectivity1$Plo_output_vr : comp->fmuData->simulationInfo->realParameter[17] = value; break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pi_vr : return setReal(comp, $Psensor1$Pad_8bit1$Pi_vr, value); break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_value_vr : return setReal(comp, $Psensor1$Pad_8bit1$Pad_8bitblock1$Plsb_vr, value); break;
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Po_vr : return setReal(comp, $Plf_1_sensor_reading_vr, value); break;
        case $Psensor1$Pad_8bit1$Po_vr : return setReal(comp, $Plf_1_sensor_reading_vr, value); break;
        case $Psensor1$Pcalculate_sensor_position1$Probot_state$lB1$rB_vr : return setReal(comp, $Probot_x_vr, value); break;
        case $Psensor1$Pcalculate_sensor_position1$Probot_state$lB2$rB_vr : return setReal(comp, $Probot_y_vr, value); break;
        case $Psensor1$Pcalculate_sensor_position1$Probot_state$lB3$rB_vr : return setReal(comp, $Probot_z_vr, value); break;
        case $Psensor1$Pcalculate_sensor_position1$Probot_state$lB4$rB_vr : return setReal(comp, $Probot_theta_vr, value); break;
        case $Psensor1$Pcombitable2d1$Pu1_vr : return setReal(comp, $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB2$rB_vr, value); break;
        case $Psensor1$Pcombitable2d1$Pu2_vr : return setReal(comp, $Psensor1$Pcalculate_sensor_position1$Psensor_position$lB1$rB_vr, value); break;
        case $Psensor1$Ppercentageto8bitvalue1$Pi_vr : return setReal(comp, $Psensor1$Pambient_light1$Po_vr, value); break;
        case $Psensor1$Ppercentageto8bitvalue1$Po_vr : return setReal(comp, $Psensor1$Pad_8bit1$Pi_vr, value); break;
        case $Psensor1$Praw_to_reflectivity1$Praw_map_reading_vr : return setReal(comp, $Psensor1$Pcombitable2d1$Py_vr, value); break;
        case $Psensor1$Praw_to_reflectivity1$Preflectivity_vr : return setReal(comp, $Psensor1$Pambient_light1$Pi_vr, value); break;
        case $Psensor1$Probot_state$lB1$rB_vr : return setReal(comp, $Probot_x_vr, value); break;
        case $Psensor1$Probot_state$lB2$rB_vr : return setReal(comp, $Probot_y_vr, value); break;
        case $Psensor1$Probot_state$lB3$rB_vr : return setReal(comp, $Probot_z_vr, value); break;
        case $Psensor1$Probot_state$lB4$rB_vr : return setReal(comp, $Probot_theta_vr, value); break;
        case $Psensor1$Psensor_output_vr : return setReal(comp, $Plf_1_sensor_reading_vr, value); break;
        default:
            return fmi2Error;
    }
    return fmi2OK;
  }
  
  fmi2Integer getInteger(ModelInstance* comp, const fmi2ValueReference vr) {
    switch (vr) {
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_level_vr : return comp->fmuData->localData[0]->integerVars[0]; break;
        case $Psensor1$Pcombitable2d1$Psmoothness_vr : return comp->fmuData->simulationInfo->integerParameter[0]; break;
        default:
            return 0;
    }
  }
  fmi2Status setInteger(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Integer value) {
    switch (vr) {
        case $Psensor1$Pad_8bit1$Pad_8bitblock1$Pnoise_level_vr : comp->fmuData->localData[0]->integerVars[0] = value; break;
        case $Psensor1$Pcombitable2d1$Psmoothness_vr : comp->fmuData->simulationInfo->integerParameter[0] = value; break;
        default:
            return fmi2Error;
    }
    return fmi2OK;
  }
  fmi2Boolean getBoolean(ModelInstance* comp, const fmi2ValueReference vr) {
    switch (vr) {
        case $Psensor1$Pcombitable2d1$PtableOnFile_vr : return comp->fmuData->simulationInfo->booleanParameter[0]; break;
        case $Psensor1$Pcombitable2d1$PverboseRead_vr : return comp->fmuData->simulationInfo->booleanParameter[1]; break;
        default:
            return fmi2False;
    }
  }
  
  fmi2Status setBoolean(ModelInstance* comp, const fmi2ValueReference vr, const fmi2Boolean value) {
    switch (vr) {
        case $Psensor1$Pcombitable2d1$PtableOnFile_vr : comp->fmuData->simulationInfo->booleanParameter[0] = value; break;
        case $Psensor1$Pcombitable2d1$PverboseRead_vr : comp->fmuData->simulationInfo->booleanParameter[1] = value; break;
        default:
            return fmi2Error;
    }
    return fmi2OK;
  }
  
  fmi2String getString(ModelInstance* comp, const fmi2ValueReference vr) {
    switch (vr) {
        case $Psensor1$Pcombitable2d1$PfileName_vr : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[0]); break;
        case $Psensor1$Pcombitable2d1$PtableName_vr : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[1]); break;
        case $Psensor1$PfileNameMapTable_vr : return MMC_STRINGDATA(comp->fmuData->simulationInfo->stringParameter[2]); break;
        default:
            return "";
    }
  }
  
  fmi2Status setString(ModelInstance* comp, const fmi2ValueReference vr, fmi2String value) {
    switch (vr) {
        case $Psensor1$Pcombitable2d1$PfileName_vr : comp->fmuData->simulationInfo->stringParameter[0] = mmc_mk_scon(value); break;
        case $Psensor1$Pcombitable2d1$PtableName_vr : comp->fmuData->simulationInfo->stringParameter[1] = mmc_mk_scon(value); break;
        case $Psensor1$PfileNameMapTable_vr : comp->fmuData->simulationInfo->stringParameter[2] = mmc_mk_scon(value); break;
        default:
            return fmi2Error;
    }
    return fmi2OK;
  }
  
  fmi2Status setExternalFunction(ModelInstance* c, const fmi2ValueReference vr, const void* value){
    switch (vr) {
        default:
            return fmi2Error;
    }
    return fmi2OK;
  }
  

#ifdef __cplusplus
}
#endif

