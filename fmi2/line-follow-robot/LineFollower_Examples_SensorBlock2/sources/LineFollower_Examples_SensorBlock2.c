/* Main Simulation File */
#include "LineFollower_Examples_SensorBlock2_model.h"


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int LineFollower_Examples_SensorBlock2_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->localData[0]->realVars[1] /* robot_theta variable */ = data->simulationInfo->inputVars[0];
  data->localData[0]->realVars[2] /* robot_x variable */ = data->simulationInfo->inputVars[1];
  data->localData[0]->realVars[3] /* robot_y variable */ = data->simulationInfo->inputVars[2];
  data->localData[0]->realVars[4] /* robot_z variable */ = data->simulationInfo->inputVars[3];
  
  TRACE_POP
  return 0;
}

int LineFollower_Examples_SensorBlock2_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->inputVars[0] = data->modelData->realVarsData[1].attribute.start;
  data->simulationInfo->inputVars[1] = data->modelData->realVarsData[2].attribute.start;
  data->simulationInfo->inputVars[2] = data->modelData->realVarsData[3].attribute.start;
  data->simulationInfo->inputVars[3] = data->modelData->realVarsData[4].attribute.start;
  
  TRACE_POP
  return 0;
}

int LineFollower_Examples_SensorBlock2_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->modelData->realVarsData[1].attribute.start = data->simulationInfo->inputVars[0];
  data->modelData->realVarsData[2].attribute.start = data->simulationInfo->inputVars[1];
  data->modelData->realVarsData[3].attribute.start = data->simulationInfo->inputVars[2];
  data->modelData->realVarsData[4].attribute.start = data->simulationInfo->inputVars[3];
  
  TRACE_POP
  return 0;
}

int LineFollower_Examples_SensorBlock2_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  names[0] = (char *) data->modelData->realVarsData[1].info.name;
  names[1] = (char *) data->modelData->realVarsData[2].info.name;
  names[2] = (char *) data->modelData->realVarsData[3].info.name;
  names[3] = (char *) data->modelData->realVarsData[4].info.name;
  
  TRACE_POP
  return 0;
}

int LineFollower_Examples_SensorBlock2_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->outputVars[0] = data->localData[0]->realVars[0] /* lf_1_sensor_reading variable */;
  
  TRACE_POP
  return 0;
}


/*
 equation index: 19
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._rotated_y = sensor1.calculate_sensor_position1.lf_positions[1] * sin(robot_theta) + sensor1.calculate_sensor_position1.lf_positions[2] * cos(robot_theta)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  data->localData[0]->realVars[16] /* sensor1._calculate_sensor_position1._rotated_y variable */ = (data->simulationInfo->realParameter[10] /* sensor1._calculate_sensor_position1._lf_positions[1] PARAM */) * (sin(data->localData[0]->realVars[1] /* robot_theta variable */)) + (data->simulationInfo->realParameter[11] /* sensor1._calculate_sensor_position1._lf_positions[2] PARAM */) * (cos(data->localData[0]->realVars[1] /* robot_theta variable */));
  TRACE_POP
}
/*
 equation index: 20
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._sensor_position[2] = robot_y + sensor1.calculate_sensor_position1.rotated_y
 */
void LineFollower_Examples_SensorBlock2_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  data->localData[0]->realVars[18] /* sensor1._calculate_sensor_position1._sensor_position[2] variable */ = data->localData[0]->realVars[3] /* robot_y variable */ + data->localData[0]->realVars[16] /* sensor1._calculate_sensor_position1._rotated_y variable */;
  TRACE_POP
}
/*
 equation index: 21
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._rotated_x = sensor1.calculate_sensor_position1.lf_positions[1] * cos(robot_theta) - sensor1.calculate_sensor_position1.lf_positions[2] * sin(robot_theta)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  data->localData[0]->realVars[15] /* sensor1._calculate_sensor_position1._rotated_x variable */ = (data->simulationInfo->realParameter[10] /* sensor1._calculate_sensor_position1._lf_positions[1] PARAM */) * (cos(data->localData[0]->realVars[1] /* robot_theta variable */)) - ((data->simulationInfo->realParameter[11] /* sensor1._calculate_sensor_position1._lf_positions[2] PARAM */) * (sin(data->localData[0]->realVars[1] /* robot_theta variable */)));
  TRACE_POP
}
/*
 equation index: 22
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._sensor_position[1] = robot_x + sensor1.calculate_sensor_position1.rotated_x
 */
void LineFollower_Examples_SensorBlock2_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  data->localData[0]->realVars[17] /* sensor1._calculate_sensor_position1._sensor_position[1] variable */ = data->localData[0]->realVars[2] /* robot_x variable */ + data->localData[0]->realVars[15] /* sensor1._calculate_sensor_position1._rotated_x variable */;
  TRACE_POP
}
/*
 equation index: 23
 type: SIMPLE_ASSIGN
 sensor1._combitable2d1._y = Modelica.Blocks.Tables.CombiTable2D$sensor1$combitable2d1.getTableValue(sensor1.combitable2d1.tableID, sensor1.calculate_sensor_position1.sensor_position[2], sensor1.calculate_sensor_position1.sensor_position[1], sensor1.combitable2d1.tableOnFileRead)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  data->localData[0]->realVars[19] /* sensor1._combitable2d1._y variable */ = omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue(threadData, data->simulationInfo->extObjs[0] /* sensor1._combitable2d1._tableID EXTOBJ: Modelica.Blocks.Types.ExternalCombiTable2D */, data->localData[0]->realVars[18] /* sensor1._calculate_sensor_position1._sensor_position[2] variable */, data->localData[0]->realVars[17] /* sensor1._calculate_sensor_position1._sensor_position[1] variable */, data->simulationInfo->realParameter[12] /* sensor1._combitable2d1._tableOnFileRead PARAM */);
  TRACE_POP
}
/*
 equation index: 24
 type: SIMPLE_ASSIGN
 sensor1._ambient_light1._i = sensor1.raw_to_reflectivity1.hi_output + (sensor1.combitable2d1.y - sensor1.raw_to_reflectivity1.hi_input) * DIVISION(sensor1.raw_to_reflectivity1.hi_output - sensor1.raw_to_reflectivity1.lo_output, sensor1.raw_to_reflectivity1.hi_input - sensor1.raw_to_reflectivity1.lo_input)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  data->localData[0]->realVars[12] /* sensor1._ambient_light1._i variable */ = data->simulationInfo->realParameter[15] /* sensor1._raw_to_reflectivity1._hi_output PARAM */ + (data->localData[0]->realVars[19] /* sensor1._combitable2d1._y variable */ - data->simulationInfo->realParameter[14] /* sensor1._raw_to_reflectivity1._hi_input PARAM */) * (DIVISION_SIM(data->simulationInfo->realParameter[15] /* sensor1._raw_to_reflectivity1._hi_output PARAM */ - data->simulationInfo->realParameter[17] /* sensor1._raw_to_reflectivity1._lo_output PARAM */,data->simulationInfo->realParameter[14] /* sensor1._raw_to_reflectivity1._hi_input PARAM */ - data->simulationInfo->realParameter[16] /* sensor1._raw_to_reflectivity1._lo_input PARAM */,"sensor1.raw_to_reflectivity1.hi_input - sensor1.raw_to_reflectivity1.lo_input",equationIndexes));
  TRACE_POP
}
/*
 equation index: 25
 type: SIMPLE_ASSIGN
 sensor1._ambient_light1._reflected_power = (sensor1.ambient_light1.led_power + sensor1.ambient_light1.ambient_light) * sensor1.ambient_light1.i
 */
void LineFollower_Examples_SensorBlock2_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */ = (data->simulationInfo->realParameter[7] /* sensor1._ambient_light1._led_power PARAM */ + data->simulationInfo->realParameter[6] /* sensor1._ambient_light1._ambient_light PARAM */) * (data->localData[0]->realVars[12] /* sensor1._ambient_light1._i variable */);
  TRACE_POP
}
/*
 equation index: 26
 type: SIMPLE_ASSIGN
 sensor1._ambient_light1._o = if sensor1.ambient_light1.reflected_power <= sensor1.ambient_light1.rx_power_off then 0.0 else if sensor1.ambient_light1.reflected_power >= sensor1.ambient_light1.rx_power_on then 1.0 else DIVISION(sensor1.ambient_light1.reflected_power - sensor1.ambient_light1.rx_power_off, sensor1.ambient_light1.rx_power_on - sensor1.ambient_light1.rx_power_off)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  RELATIONHYSTERESIS(tmp16, data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */, data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */, 0, LessEq);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = 0.0;
  }
  else
  {
    RELATIONHYSTERESIS(tmp17, data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */, data->simulationInfo->realParameter[9] /* sensor1._ambient_light1._rx_power_on PARAM */, 1, GreaterEq);
    tmp19 = (tmp17?1.0:DIVISION_SIM(data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */ - data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */,data->simulationInfo->realParameter[9] /* sensor1._ambient_light1._rx_power_on PARAM */ - data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */,"sensor1.ambient_light1.rx_power_on - sensor1.ambient_light1.rx_power_off",equationIndexes));
  }
  data->localData[0]->realVars[13] /* sensor1._ambient_light1._o variable */ = tmp19;
  TRACE_POP
}
/*
 equation index: 27
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._i = sensor1.percentageto8bitvalue1.k * sensor1.ambient_light1.o
 */
void LineFollower_Examples_SensorBlock2_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  data->localData[0]->realVars[11] /* sensor1._ad_8bit1._i variable */ = (data->simulationInfo->realParameter[13] /* sensor1._percentageto8bitvalue1._k PARAM */) * (data->localData[0]->realVars[13] /* sensor1._ambient_light1._o variable */);
  TRACE_POP
}
/*
 equation index: 28
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._hold_signal = sensor1.ad_8bit1.i + sensor1.ad_8bit1.ad_8bitblock1.lsb
 */
void LineFollower_Examples_SensorBlock2_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */ = data->localData[0]->realVars[11] /* sensor1._ad_8bit1._i variable */ + data->localData[0]->realVars[7] /* sensor1._ad_8bit1._ad_8bitblock1._lsb variable */;
  TRACE_POP
}
/*
 equation index: 29
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._windowed_signal = if sensor1.ad_8bit1.ad_8bitblock1.hold_signal <= sensor1.ad_8bit1.ad_8bitblock1.minimum then sensor1.ad_8bit1.ad_8bitblock1.minimum + sensor1.ad_8bit1.ad_8bitblock1.half_lsb else if sensor1.ad_8bit1.ad_8bitblock1.hold_signal >= sensor1.ad_8bit1.ad_8bitblock1.maximum then sensor1.ad_8bit1.ad_8bitblock1.maximum - sensor1.ad_8bit1.ad_8bitblock1.half_lsb else sensor1.ad_8bit1.ad_8bitblock1.hold_signal
 */
void LineFollower_Examples_SensorBlock2_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  RELATIONHYSTERESIS(tmp20, data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */, data->simulationInfo->realParameter[5] /* sensor1._ad_8bit1._ad_8bitblock1._minimum PARAM */, 2, LessEq);
  tmp22 = (modelica_boolean)tmp20;
  if(tmp22)
  {
    tmp23 = data->simulationInfo->realParameter[5] /* sensor1._ad_8bit1._ad_8bitblock1._minimum PARAM */ + data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp21, data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */, data->simulationInfo->realParameter[4] /* sensor1._ad_8bit1._ad_8bitblock1._maximum PARAM */, 3, GreaterEq);
    tmp23 = (tmp21?data->simulationInfo->realParameter[4] /* sensor1._ad_8bit1._ad_8bitblock1._maximum PARAM */ - data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */:data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */);
  }
  data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */ = tmp23;
  TRACE_POP
}
/*
 equation index: 30
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal = if sensor1.ad_8bit1.ad_8bitblock1.windowed_signal < 0.0 then sensor1.ad_8bit1.ad_8bitblock1.windowed_signal - sensor1.ad_8bit1.ad_8bitblock1.half_lsb else sensor1.ad_8bit1.ad_8bitblock1.windowed_signal + sensor1.ad_8bit1.ad_8bitblock1.half_lsb
 */
void LineFollower_Examples_SensorBlock2_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  modelica_boolean tmp24;
  RELATIONHYSTERESIS(tmp24, data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */, 0.0, 4, Less);
  data->localData[0]->realVars[9] /* sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal variable */ = (tmp24?data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */ - data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */:data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */ + data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */);
  TRACE_POP
}
/*
 equation index: 31
 type: SIMPLE_ASSIGN
 lf_1_sensor_reading = sensor1.ad_8bit1.ad_8bitblock1.quantisized_signal - mod(sensor1.ad_8bit1.ad_8bitblock1.quantisized_signal, sensor1.ad_8bit1.ad_8bitblock1.lsb, 0)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  data->localData[0]->realVars[0] /* lf_1_sensor_reading variable */ = data->localData[0]->realVars[9] /* sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal variable */ - _event_mod_real(data->localData[0]->realVars[9] /* sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal variable */, data->localData[0]->realVars[7] /* sensor1._ad_8bit1._ad_8bitblock1._lsb variable */, ((modelica_integer) 0), data, threadData);
  TRACE_POP
}


int LineFollower_Examples_SensorBlock2_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  LineFollower_Examples_SensorBlock2_functionLocalKnownVars(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_19(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_20(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_21(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_22(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_23(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_24(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_25(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_26(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_27(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_28(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_29(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_30(data, threadData);

  LineFollower_Examples_SensorBlock2_eqFunction_31(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int LineFollower_Examples_SensorBlock2_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int LineFollower_Examples_SensorBlock2_symEulerUpdate(DATA *data, modelica_real dt)
{
  return -1;
}



int LineFollower_Examples_SensorBlock2_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  LineFollower_Examples_SensorBlock2_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "LineFollower_Examples_SensorBlock2_12jac.h"
#include "LineFollower_Examples_SensorBlock2_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks LineFollower_Examples_SensorBlock2_callback = {
   NULL,
   NULL,
   NULL,
   LineFollower_Examples_SensorBlock2_callExternalObjectConstructors,
   LineFollower_Examples_SensorBlock2_callExternalObjectDestructors,
   LineFollower_Examples_SensorBlock2_initialNonLinearSystem,
   LineFollower_Examples_SensorBlock2_initialLinearSystem,
   LineFollower_Examples_SensorBlock2_initialMixedSystem,
   LineFollower_Examples_SensorBlock2_initializeStateSets,
   LineFollower_Examples_SensorBlock2_initializeDAEmodeData,
   LineFollower_Examples_SensorBlock2_functionODE,
   LineFollower_Examples_SensorBlock2_functionAlgebraics,
   LineFollower_Examples_SensorBlock2_functionDAE,
   LineFollower_Examples_SensorBlock2_functionLocalKnownVars,
   LineFollower_Examples_SensorBlock2_input_function,
   LineFollower_Examples_SensorBlock2_input_function_init,
   LineFollower_Examples_SensorBlock2_input_function_updateStartValues,
   LineFollower_Examples_SensorBlock2_output_function,
   LineFollower_Examples_SensorBlock2_function_storeDelayed,
   LineFollower_Examples_SensorBlock2_updateBoundVariableAttributes,
   0 /* useHomotopy */,
   LineFollower_Examples_SensorBlock2_functionInitialEquations,
   LineFollower_Examples_SensorBlock2_functionInitialEquations_lambda0,
   LineFollower_Examples_SensorBlock2_functionRemovedInitialEquations,
   LineFollower_Examples_SensorBlock2_updateBoundParameters,
   LineFollower_Examples_SensorBlock2_checkForAsserts,
   LineFollower_Examples_SensorBlock2_function_ZeroCrossingsEquations,
   LineFollower_Examples_SensorBlock2_function_ZeroCrossings,
   LineFollower_Examples_SensorBlock2_function_updateRelations,
   LineFollower_Examples_SensorBlock2_checkForDiscreteChanges,
   LineFollower_Examples_SensorBlock2_zeroCrossingDescription,
   LineFollower_Examples_SensorBlock2_relationDescription,
   LineFollower_Examples_SensorBlock2_function_initSample,
   LineFollower_Examples_SensorBlock2_INDEX_JAC_A,
   LineFollower_Examples_SensorBlock2_INDEX_JAC_B,
   LineFollower_Examples_SensorBlock2_INDEX_JAC_C,
   LineFollower_Examples_SensorBlock2_INDEX_JAC_D,
   LineFollower_Examples_SensorBlock2_initialAnalyticJacobianA,
   LineFollower_Examples_SensorBlock2_initialAnalyticJacobianB,
   LineFollower_Examples_SensorBlock2_initialAnalyticJacobianC,
   LineFollower_Examples_SensorBlock2_initialAnalyticJacobianD,
   LineFollower_Examples_SensorBlock2_functionJacA_column,
   LineFollower_Examples_SensorBlock2_functionJacB_column,
   LineFollower_Examples_SensorBlock2_functionJacC_column,
   LineFollower_Examples_SensorBlock2_functionJacD_column,
   LineFollower_Examples_SensorBlock2_linear_model_frame,
   LineFollower_Examples_SensorBlock2_linear_model_datarecovery_frame,
   LineFollower_Examples_SensorBlock2_mayer,
   LineFollower_Examples_SensorBlock2_lagrange,
   LineFollower_Examples_SensorBlock2_pickUpBoundsForInputsInOptimization,
   LineFollower_Examples_SensorBlock2_setInputData,
   LineFollower_Examples_SensorBlock2_getTimeGrid,
   LineFollower_Examples_SensorBlock2_symEulerUpdate,
   LineFollower_Examples_SensorBlock2_function_initSynchronous,
   LineFollower_Examples_SensorBlock2_function_updateSynchronous,
   LineFollower_Examples_SensorBlock2_function_equationsSynchronous,
   LineFollower_Examples_SensorBlock2_read_input_fmu
   #ifdef FMU_EXPERIMENTAL
   ,LineFollower_Examples_SensorBlock2_functionODE_Partial
   ,LineFollower_Examples_SensorBlock2_functionFMIJacobian
   #endif
   ,LineFollower_Examples_SensorBlock2_inputNames


};

void LineFollower_Examples_SensorBlock2_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &LineFollower_Examples_SensorBlock2_callback;
  data->modelData->modelName = "LineFollower.Examples.SensorBlock2";
  data->modelData->modelFilePrefix = "LineFollower_Examples_SensorBlock2";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/home/adrpo33/dev/OMTesting/LineFollower/Examples";
  data->modelData->modelGUID = "{bb5eedb0-8d6b-4a9c-9b34-2d7584c3293e}";
  data->modelData->fmuResourceLocation = NULL;
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData =
  #include "LineFollower_Examples_SensorBlock2_info.c"
  ;
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 2*0+20+0+0 + 0;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 1;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 18;
  data->modelData->nParametersInteger = 1;
  data->modelData->nParametersBoolean = 2;
  data->modelData->nParametersString = 3;
  data->modelData->nInputVars = 4;
  data->modelData->nOutputVars = 1;
  
  data->modelData->nAliasReal = 19;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 6;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 5;
  data->modelData->nMathEvents = 2;
  data->modelData->nExtObjs = 1;
  data->modelData->modelDataXml.fileName = "LineFollower_Examples_SensorBlock2_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 8;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 41;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 4;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

#ifdef __cplusplus
}
#endif

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

