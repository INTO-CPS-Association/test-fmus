/* Algebraic */
#include "LineFollower_Examples_SensorBlock1_model.h"

#ifdef __cplusplus
extern "C" {
#endif


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
extern void LineFollower_Examples_SensorBlock1_eqFunction_31(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
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

  LineFollower_Examples_SensorBlock1_eqFunction_31(data, threadData);
}
/* for continuous time variables */
int LineFollower_Examples_SensorBlock1_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  data->simulationInfo->callStatistics.functionAlgebraics++;
  
  functionAlg_system0(data, threadData);

  LineFollower_Examples_SensorBlock1_function_savePreSynchronous(data, threadData);
  
  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
