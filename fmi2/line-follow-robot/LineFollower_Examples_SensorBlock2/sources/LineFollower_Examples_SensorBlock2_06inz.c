/* Initialization */
#include "LineFollower_Examples_SensorBlock2_model.h"
#include "LineFollower_Examples_SensorBlock2_11mix.h"
#include "LineFollower_Examples_SensorBlock2_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void LineFollower_Examples_SensorBlock2_functionInitialEquations_0(DATA *data, threadData_t *threadData);


/*
 equation index: 1
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._lsb = DIVISION(sensor1.ad_8bit1.ad_8bitblock1.maximum - sensor1.ad_8bit1.ad_8bitblock1.minimum, -1.0 + sensor1.ad_8bit1.ad_8bitblock1.bitPower)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[7] /* sensor1._ad_8bit1._ad_8bitblock1._lsb variable */ = DIVISION_SIM(data->simulationInfo->realParameter[4] /* sensor1._ad_8bit1._ad_8bitblock1._maximum PARAM */ - data->simulationInfo->realParameter[5] /* sensor1._ad_8bit1._ad_8bitblock1._minimum PARAM */,-1.0 + data->simulationInfo->realParameter[2] /* sensor1._ad_8bit1._ad_8bitblock1._bitPower PARAM */,"-1.0 + sensor1.ad_8bit1.ad_8bitblock1.bitPower",equationIndexes);
  TRACE_POP
}

/*
 equation index: 2
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._half_lsb = 0.5 * sensor1.ad_8bit1.ad_8bitblock1.lsb
 */
void LineFollower_Examples_SensorBlock2_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */ = (0.5) * (data->localData[0]->realVars[7] /* sensor1._ad_8bit1._ad_8bitblock1._lsb variable */);
  TRACE_POP
}

/*
 equation index: 3
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._rotated_x = sensor1.calculate_sensor_position1.lf_positions[1] * cos(robot_theta) - sensor1.calculate_sensor_position1.lf_positions[2] * sin(robot_theta)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[15] /* sensor1._calculate_sensor_position1._rotated_x variable */ = (data->simulationInfo->realParameter[10] /* sensor1._calculate_sensor_position1._lf_positions[1] PARAM */) * (cos(data->localData[0]->realVars[1] /* robot_theta variable */)) - ((data->simulationInfo->realParameter[11] /* sensor1._calculate_sensor_position1._lf_positions[2] PARAM */) * (sin(data->localData[0]->realVars[1] /* robot_theta variable */)));
  TRACE_POP
}

/*
 equation index: 4
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._rotated_y = sensor1.calculate_sensor_position1.lf_positions[1] * sin(robot_theta) + sensor1.calculate_sensor_position1.lf_positions[2] * cos(robot_theta)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  data->localData[0]->realVars[16] /* sensor1._calculate_sensor_position1._rotated_y variable */ = (data->simulationInfo->realParameter[10] /* sensor1._calculate_sensor_position1._lf_positions[1] PARAM */) * (sin(data->localData[0]->realVars[1] /* robot_theta variable */)) + (data->simulationInfo->realParameter[11] /* sensor1._calculate_sensor_position1._lf_positions[2] PARAM */) * (cos(data->localData[0]->realVars[1] /* robot_theta variable */));
  TRACE_POP
}

/*
 equation index: 5
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._sensor_position[1] = robot_x + sensor1.calculate_sensor_position1.rotated_x
 */
void LineFollower_Examples_SensorBlock2_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  data->localData[0]->realVars[17] /* sensor1._calculate_sensor_position1._sensor_position[1] variable */ = data->localData[0]->realVars[2] /* robot_x variable */ + data->localData[0]->realVars[15] /* sensor1._calculate_sensor_position1._rotated_x variable */;
  TRACE_POP
}

/*
 equation index: 6
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._sensor_position[2] = robot_y + sensor1.calculate_sensor_position1.rotated_y
 */
void LineFollower_Examples_SensorBlock2_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->realVars[18] /* sensor1._calculate_sensor_position1._sensor_position[2] variable */ = data->localData[0]->realVars[3] /* robot_y variable */ + data->localData[0]->realVars[16] /* sensor1._calculate_sensor_position1._rotated_y variable */;
  TRACE_POP
}

/*
 equation index: 7
 type: ALGORITHM
 
   sensor1.combitable2d1.tableOnFileRead := Modelica.Blocks.Tables.CombiTable2D$sensor1$combitable2d1.readTableData(sensor1.combitable2d1.tableID, false, sensor1.combitable2d1.verboseRead);
 */
void LineFollower_Examples_SensorBlock2_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->simulationInfo->realParameter[12] /* sensor1._combitable2d1._tableOnFileRead PARAM */ = omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData(threadData, data->simulationInfo->extObjs[0] /* sensor1._combitable2d1._tableID EXTOBJ: Modelica.Blocks.Types.ExternalCombiTable2D */, 0, data->simulationInfo->booleanParameter[1] /* sensor1._combitable2d1._verboseRead PARAM */);
  TRACE_POP
}

/*
 equation index: 8
 type: SIMPLE_ASSIGN
 sensor1._combitable2d1._y = Modelica.Blocks.Tables.CombiTable2D$sensor1$combitable2d1.getTableValue(sensor1.combitable2d1.tableID, sensor1.calculate_sensor_position1.sensor_position[2], sensor1.calculate_sensor_position1.sensor_position[1], sensor1.combitable2d1.tableOnFileRead)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[19] /* sensor1._combitable2d1._y variable */ = omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue(threadData, data->simulationInfo->extObjs[0] /* sensor1._combitable2d1._tableID EXTOBJ: Modelica.Blocks.Types.ExternalCombiTable2D */, data->localData[0]->realVars[18] /* sensor1._calculate_sensor_position1._sensor_position[2] variable */, data->localData[0]->realVars[17] /* sensor1._calculate_sensor_position1._sensor_position[1] variable */, data->simulationInfo->realParameter[12] /* sensor1._combitable2d1._tableOnFileRead PARAM */);
  TRACE_POP
}

/*
 equation index: 9
 type: SIMPLE_ASSIGN
 sensor1._ambient_light1._i = sensor1.raw_to_reflectivity1.hi_output + (sensor1.combitable2d1.y - sensor1.raw_to_reflectivity1.hi_input) * DIVISION(sensor1.raw_to_reflectivity1.hi_output - sensor1.raw_to_reflectivity1.lo_output, sensor1.raw_to_reflectivity1.hi_input - sensor1.raw_to_reflectivity1.lo_input)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  data->localData[0]->realVars[12] /* sensor1._ambient_light1._i variable */ = data->simulationInfo->realParameter[15] /* sensor1._raw_to_reflectivity1._hi_output PARAM */ + (data->localData[0]->realVars[19] /* sensor1._combitable2d1._y variable */ - data->simulationInfo->realParameter[14] /* sensor1._raw_to_reflectivity1._hi_input PARAM */) * (DIVISION_SIM(data->simulationInfo->realParameter[15] /* sensor1._raw_to_reflectivity1._hi_output PARAM */ - data->simulationInfo->realParameter[17] /* sensor1._raw_to_reflectivity1._lo_output PARAM */,data->simulationInfo->realParameter[14] /* sensor1._raw_to_reflectivity1._hi_input PARAM */ - data->simulationInfo->realParameter[16] /* sensor1._raw_to_reflectivity1._lo_input PARAM */,"sensor1.raw_to_reflectivity1.hi_input - sensor1.raw_to_reflectivity1.lo_input",equationIndexes));
  TRACE_POP
}

/*
 equation index: 10
 type: SIMPLE_ASSIGN
 sensor1._ambient_light1._reflected_power = (sensor1.ambient_light1.led_power + sensor1.ambient_light1.ambient_light) * sensor1.ambient_light1.i
 */
void LineFollower_Examples_SensorBlock2_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */ = (data->simulationInfo->realParameter[7] /* sensor1._ambient_light1._led_power PARAM */ + data->simulationInfo->realParameter[6] /* sensor1._ambient_light1._ambient_light PARAM */) * (data->localData[0]->realVars[12] /* sensor1._ambient_light1._i variable */);
  TRACE_POP
}

/*
 equation index: 11
 type: SIMPLE_ASSIGN
 sensor1._ambient_light1._o = if sensor1.ambient_light1.reflected_power <= sensor1.ambient_light1.rx_power_off then 0.0 else if sensor1.ambient_light1.reflected_power >= sensor1.ambient_light1.rx_power_on then 1.0 else DIVISION(sensor1.ambient_light1.reflected_power - sensor1.ambient_light1.rx_power_off, sensor1.ambient_light1.rx_power_on - sensor1.ambient_light1.rx_power_off)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = LessEq(data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */,data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = 0.0;
  }
  else
  {
    tmp1 = GreaterEq(data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */,data->simulationInfo->realParameter[9] /* sensor1._ambient_light1._rx_power_on PARAM */);
    tmp3 = (tmp1?1.0:DIVISION_SIM(data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */ - data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */,data->simulationInfo->realParameter[9] /* sensor1._ambient_light1._rx_power_on PARAM */ - data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */,"sensor1.ambient_light1.rx_power_on - sensor1.ambient_light1.rx_power_off",equationIndexes));
  }
  data->localData[0]->realVars[13] /* sensor1._ambient_light1._o variable */ = tmp3;
  TRACE_POP
}

/*
 equation index: 12
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._i = sensor1.percentageto8bitvalue1.k * sensor1.ambient_light1.o
 */
void LineFollower_Examples_SensorBlock2_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[11] /* sensor1._ad_8bit1._i variable */ = (data->simulationInfo->realParameter[13] /* sensor1._percentageto8bitvalue1._k PARAM */) * (data->localData[0]->realVars[13] /* sensor1._ambient_light1._o variable */);
  TRACE_POP
}

/*
 equation index: 13
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._hold_signal = sensor1.ad_8bit1.i + sensor1.ad_8bit1.ad_8bitblock1.lsb
 */
void LineFollower_Examples_SensorBlock2_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */ = data->localData[0]->realVars[11] /* sensor1._ad_8bit1._i variable */ + data->localData[0]->realVars[7] /* sensor1._ad_8bit1._ad_8bitblock1._lsb variable */;
  TRACE_POP
}

/*
 equation index: 14
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._windowed_signal = if sensor1.ad_8bit1.ad_8bitblock1.hold_signal <= sensor1.ad_8bit1.ad_8bitblock1.minimum then sensor1.ad_8bit1.ad_8bitblock1.minimum + sensor1.ad_8bit1.ad_8bitblock1.half_lsb else if sensor1.ad_8bit1.ad_8bitblock1.hold_signal >= sensor1.ad_8bit1.ad_8bitblock1.maximum then sensor1.ad_8bit1.ad_8bitblock1.maximum - sensor1.ad_8bit1.ad_8bitblock1.half_lsb else sensor1.ad_8bit1.ad_8bitblock1.hold_signal
 */
void LineFollower_Examples_SensorBlock2_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  tmp4 = LessEq(data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */,data->simulationInfo->realParameter[5] /* sensor1._ad_8bit1._ad_8bitblock1._minimum PARAM */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->simulationInfo->realParameter[5] /* sensor1._ad_8bit1._ad_8bitblock1._minimum PARAM */ + data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */;
  }
  else
  {
    tmp5 = GreaterEq(data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */,data->simulationInfo->realParameter[4] /* sensor1._ad_8bit1._ad_8bitblock1._maximum PARAM */);
    tmp7 = (tmp5?data->simulationInfo->realParameter[4] /* sensor1._ad_8bit1._ad_8bitblock1._maximum PARAM */ - data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */:data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */);
  }
  data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */ = tmp7;
  TRACE_POP
}

/*
 equation index: 15
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal = if sensor1.ad_8bit1.ad_8bitblock1.windowed_signal < 0.0 then sensor1.ad_8bit1.ad_8bitblock1.windowed_signal - sensor1.ad_8bit1.ad_8bitblock1.half_lsb else sensor1.ad_8bit1.ad_8bitblock1.windowed_signal + sensor1.ad_8bit1.ad_8bitblock1.half_lsb
 */
void LineFollower_Examples_SensorBlock2_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_boolean tmp8;
  tmp8 = Less(data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */,0.0);
  data->localData[0]->realVars[9] /* sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal variable */ = (tmp8?data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */ - data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */:data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */ + data->localData[0]->realVars[5] /* sensor1._ad_8bit1._ad_8bitblock1._half_lsb variable */);
  TRACE_POP
}

/*
 equation index: 16
 type: SIMPLE_ASSIGN
 lf_1_sensor_reading = sensor1.ad_8bit1.ad_8bitblock1.quantisized_signal - mod(sensor1.ad_8bit1.ad_8bitblock1.quantisized_signal, sensor1.ad_8bit1.ad_8bitblock1.lsb)
 */
void LineFollower_Examples_SensorBlock2_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_real tmp9;
  tmp9 = data->localData[0]->realVars[7] /* sensor1._ad_8bit1._ad_8bitblock1._lsb variable */;
  if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(sensor1.ad_8bit1.ad_8bitblock1.quantisized_signal, sensor1.ad_8bit1.ad_8bitblock1.lsb)");}
  data->localData[0]->realVars[0] /* lf_1_sensor_reading variable */ = data->localData[0]->realVars[9] /* sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal variable */ - ((data->localData[0]->realVars[9] /* sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal variable */) - floor((data->localData[0]->realVars[9] /* sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal variable */) / (tmp9)) * (tmp9));
  TRACE_POP
}

/*
 equation index: 17
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._noise = 1.0
 */
void LineFollower_Examples_SensorBlock2_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  data->localData[0]->realVars[8] /* sensor1._ad_8bit1._ad_8bitblock1._noise variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 18
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._noise_level = 0.0
 */
void LineFollower_Examples_SensorBlock2_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  data->localData[0]->integerVars[0] /* sensor1._ad_8bit1._ad_8bitblock1._noise_level DISCRETE */ = 0.0;
  TRACE_POP
}
void LineFollower_Examples_SensorBlock2_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  LineFollower_Examples_SensorBlock2_eqFunction_1(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_2(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_3(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_4(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_5(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_6(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_7(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_8(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_9(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_10(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_11(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_12(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_13(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_14(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_15(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_16(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_17(data, threadData);
  LineFollower_Examples_SensorBlock2_eqFunction_18(data, threadData);
  TRACE_POP
}


int LineFollower_Examples_SensorBlock2_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  LineFollower_Examples_SensorBlock2_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int LineFollower_Examples_SensorBlock2_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int LineFollower_Examples_SensorBlock2_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}

/* funtion initialize mixed systems */
void LineFollower_Examples_SensorBlock2_initialMixedSystem(int nMixedSystems, MIXED_SYSTEM_DATA* mixedSystemData)
{
  /* initial mixed systems */
  /* initial_lambda0 mixed systems */
  /* parameter mixed systems */
  /* model mixed systems */
  /* jacobians mixed systems */
}

#if defined(__cplusplus)
}
#endif

