/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "LineFollower_Examples_SensorBlock1_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void LineFollower_Examples_SensorBlock1_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *LineFollower_Examples_SensorBlock1_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"sensor1.ambient_light1.reflected_power <= sensor1.ambient_light1.rx_power_off",
  "sensor1.ambient_light1.reflected_power >= sensor1.ambient_light1.rx_power_on",
  "sensor1.ad_8bit1.ad_8bitblock1.hold_signal <= sensor1.ad_8bit1.ad_8bitblock1.minimum",
  "sensor1.ad_8bit1.ad_8bitblock1.hold_signal >= sensor1.ad_8bit1.ad_8bitblock1.maximum",
  "sensor1.ad_8bit1.ad_8bitblock1.windowed_signal < 0.0",
  "mod(sensor1.ad_8bit1.ad_8bitblock1.quantisized_signal, sensor1.ad_8bit1.ad_8bitblock1.lsb, 0)"};
  static const int occurEqs0[] = {1,26};
  static const int occurEqs1[] = {1,26};
  static const int occurEqs2[] = {1,29};
  static const int occurEqs3[] = {1,29};
  static const int occurEqs4[] = {1,30};
  static const int occurEqs5[] = {1,31};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void LineFollower_Examples_SensorBlock1_eqFunction_19(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_20(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_21(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_22(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_23(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_24(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_25(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_26(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_27(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_28(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_29(DATA* data, threadData_t *threadData);
extern void LineFollower_Examples_SensorBlock1_eqFunction_30(DATA* data, threadData_t *threadData);

int LineFollower_Examples_SensorBlock1_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  LineFollower_Examples_SensorBlock1_eqFunction_19(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_20(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_21(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_22(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_23(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_24(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_25(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_26(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_27(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_28(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_29(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_30(data, threadData);
  
  TRACE_POP
  return 0;
}

int LineFollower_Examples_SensorBlock1_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  
  data->simulationInfo->callStatistics.functionZeroCrossings++;
  
  tmp6 = LessEqZC(data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */, data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp6) ? 1 : -1;
  tmp7 = GreaterEqZC(data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */, data->simulationInfo->realParameter[9] /* sensor1._ambient_light1._rx_power_on PARAM */, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp7) ? 1 : -1;
  tmp8 = LessEqZC(data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */, data->simulationInfo->realParameter[5] /* sensor1._ad_8bit1._ad_8bitblock1._minimum PARAM */, data->simulationInfo->storedRelations[2]);
  gout[2] = (tmp8) ? 1 : -1;
  tmp9 = GreaterEqZC(data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */, data->simulationInfo->realParameter[4] /* sensor1._ad_8bit1._ad_8bitblock1._maximum PARAM */, data->simulationInfo->storedRelations[3]);
  gout[3] = (tmp9) ? 1 : -1;
  tmp10 = LessZC(data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */, 0.0, data->simulationInfo->storedRelations[4]);
  gout[4] = (tmp10) ? 1 : -1;
  tmp11 = floor((data->localData[0]->realVars[9] /* sensor1._ad_8bit1._ad_8bitblock1._quantisized_signal variable */) / (data->localData[0]->realVars[7] /* sensor1._ad_8bit1._ad_8bitblock1._lsb variable */));
  tmp12 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)+1]));
  gout[5] = tmp11 != tmp12 ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *LineFollower_Examples_SensorBlock1_relationDescription(int i)
{
  const char *res[] = {"sensor1.ambient_light1.reflected_power <= sensor1.ambient_light1.rx_power_off",
  "sensor1.ambient_light1.reflected_power >= sensor1.ambient_light1.rx_power_on",
  "sensor1.ad_8bit1.ad_8bitblock1.hold_signal <= sensor1.ad_8bit1.ad_8bitblock1.minimum",
  "sensor1.ad_8bit1.ad_8bitblock1.hold_signal >= sensor1.ad_8bit1.ad_8bitblock1.maximum",
  "sensor1.ad_8bit1.ad_8bitblock1.windowed_signal < 0.0"};
  return res[i];
}

int LineFollower_Examples_SensorBlock1_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  
  if(evalforZeroCross) {
    tmp13 = LessEqZC(data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */, data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp13;
    tmp14 = GreaterEqZC(data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */, data->simulationInfo->realParameter[9] /* sensor1._ambient_light1._rx_power_on PARAM */, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp14;
    tmp15 = LessEqZC(data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */, data->simulationInfo->realParameter[5] /* sensor1._ad_8bit1._ad_8bitblock1._minimum PARAM */, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp15;
    tmp16 = GreaterEqZC(data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */, data->simulationInfo->realParameter[4] /* sensor1._ad_8bit1._ad_8bitblock1._maximum PARAM */, data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[3] = tmp16;
    tmp17 = LessZC(data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */, 0.0, data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[4] = tmp17;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */ <= data->simulationInfo->realParameter[8] /* sensor1._ambient_light1._rx_power_off PARAM */);
    data->simulationInfo->relations[1] = (data->localData[0]->realVars[14] /* sensor1._ambient_light1._reflected_power variable */ >= data->simulationInfo->realParameter[9] /* sensor1._ambient_light1._rx_power_on PARAM */);
    data->simulationInfo->relations[2] = (data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */ <= data->simulationInfo->realParameter[5] /* sensor1._ad_8bit1._ad_8bitblock1._minimum PARAM */);
    data->simulationInfo->relations[3] = (data->localData[0]->realVars[6] /* sensor1._ad_8bit1._ad_8bitblock1._hold_signal variable */ >= data->simulationInfo->realParameter[4] /* sensor1._ad_8bit1._ad_8bitblock1._maximum PARAM */);
    data->simulationInfo->relations[4] = (data->localData[0]->realVars[10] /* sensor1._ad_8bit1._ad_8bitblock1._windowed_signal variable */ < 0.0);
  }
  
  TRACE_POP
  return 0;
}

int LineFollower_Examples_SensorBlock1_checkForDiscreteChanges(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int needToIterate = 0;

  infoStreamPrint(LOG_EVENTS_V, 1, "check for discrete changes at time=%.12g", data->localData[0]->timeValue);
  if (ACTIVE_STREAM(LOG_EVENTS_V)) messageClose(LOG_EVENTS_V);
  
  TRACE_POP
  return needToIterate;
}

#if defined(__cplusplus)
}
#endif

