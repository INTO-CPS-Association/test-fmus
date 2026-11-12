/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "LineFollower_Examples_SensorBlock1_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int LineFollower_Examples_SensorBlock1_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}


/*
 equation index: 32
 type: SIMPLE_ASSIGN
 sensor1._fileNameMapTable = LineFollower.Components.Sensor$sensor1.getResource()
 */
void LineFollower_Examples_SensorBlock1_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  char buf[2000];
  sprintf(buf, "%s/LineFollower/Resources/Data/map.txt", data->modelData->fmuResourceLocation);
  fprintf(stderr, "resource is here: %s\n", data->modelData->fmuResourceLocation); fflush(stderr);
  data->simulationInfo->stringParameter[2] /* sensor1._fileNameMapTable PARAM */ = mmc_mk_scon(buf);
  TRACE_POP
}

/*
 equation index: 33
 type: SIMPLE_ASSIGN
 sensor1._ad_8bit1._ad_8bitblock1._bitPower = 2.0 ^ sensor1.ad_8bit1.ad_8bitblock1.bits
 */
void LineFollower_Examples_SensorBlock1_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = 2.0;
  tmp1 = data->simulationInfo->realParameter[3] /* sensor1._ad_8bit1._ad_8bitblock1._bits PARAM */;
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "Invalid root: (%g)^(%g)", tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "Invalid root: (%g)^(%g)", tmp0, tmp1);
  }
  data->simulationInfo->realParameter[2] /* sensor1._ad_8bit1._ad_8bitblock1._bitPower PARAM */ = tmp2;
  TRACE_POP
}

/*
 equation index: 34
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._lf_positions[1] = lf_position_x
 */
void LineFollower_Examples_SensorBlock1_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  data->simulationInfo->realParameter[10] /* sensor1._calculate_sensor_position1._lf_positions[1] PARAM */ = data->simulationInfo->realParameter[0] /* lf_position_x PARAM */;
  TRACE_POP
}

/*
 equation index: 35
 type: SIMPLE_ASSIGN
 sensor1._calculate_sensor_position1._lf_positions[2] = lf_position_y
 */
void LineFollower_Examples_SensorBlock1_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  data->simulationInfo->realParameter[11] /* sensor1._calculate_sensor_position1._lf_positions[2] PARAM */ = data->simulationInfo->realParameter[1] /* lf_position_y PARAM */;
  TRACE_POP
}

/*
 equation index: 36
 type: SIMPLE_ASSIGN
 sensor1._combitable2d1._tableOnFile = true
 */
void LineFollower_Examples_SensorBlock1_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  data->simulationInfo->booleanParameter[0] /* sensor1._combitable2d1._tableOnFile PARAM */ = 1;
  TRACE_POP
}

/*
 equation index: 37
 type: SIMPLE_ASSIGN
 sensor1._combitable2d1._tableName = "map"
 */
void LineFollower_Examples_SensorBlock1_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  data->simulationInfo->stringParameter[1] /* sensor1._combitable2d1._tableName PARAM */ = _OMC_LIT1;
  TRACE_POP
}

/*
 equation index: 38
 type: SIMPLE_ASSIGN
 sensor1._combitable2d1._fileName = sensor1.fileNameMapTable
 */
void LineFollower_Examples_SensorBlock1_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  data->simulationInfo->stringParameter[0] /* sensor1._combitable2d1._fileName PARAM */ = data->simulationInfo->stringParameter[2] /* sensor1._fileNameMapTable PARAM */;
  TRACE_POP
}

/*
 equation index: 39
 type: SIMPLE_ASSIGN
 sensor1._combitable2d1._smoothness = Modelica.Blocks.Types.Smoothness.LinearSegments
 */
void LineFollower_Examples_SensorBlock1_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  data->simulationInfo->integerParameter[0] /* sensor1._combitable2d1._smoothness PARAM */ = 1;
  TRACE_POP
}

/*
 equation index: 40
 type: ALGORITHM
 
   assert(sensor1.combitable2d1.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and sensor1.combitable2d1.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= sensor1.combitable2d1.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(sensor1.combitable2d1.smoothness, "d"));
 */
void LineFollower_Examples_SensorBlock1_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  modelica_boolean tmp7;
  modelica_boolean tmp8;
  static const MMC_DEFSTRINGLIT(tmp9,201,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= sensor1.combitable2d1.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp10;
  static int tmp11 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp11)
  {
    tmp7 = GreaterEq((modelica_integer)data->simulationInfo->integerParameter[0] /* sensor1._combitable2d1._smoothness PARAM */,1);
    tmp8 = LessEq((modelica_integer)data->simulationInfo->integerParameter[0] /* sensor1._combitable2d1._smoothness PARAM */,5);
    if(!(tmp7 && tmp8))
    {
      tmp10 = modelica_integer_to_modelica_string_format((modelica_integer)data->simulationInfo->integerParameter[0] /* sensor1._combitable2d1._smoothness PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp9),tmp10);
      {
        FILE_INFO info = {"c:/home/adrpo33/dev/OpenModelica/build/lib/omlibrary/Modelica 3.2.2/Blocks/Tables.mo",629,5,631,61,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsensor1.combitable2d1.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and sensor1.combitable2d1.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp11 = 1;
    }
  }
  TRACE_POP
}
int LineFollower_Examples_SensorBlock1_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  LineFollower_Examples_SensorBlock1_eqFunction_32(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_33(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_34(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_35(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_36(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_37(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_38(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_39(data, threadData);

  LineFollower_Examples_SensorBlock1_eqFunction_40(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

