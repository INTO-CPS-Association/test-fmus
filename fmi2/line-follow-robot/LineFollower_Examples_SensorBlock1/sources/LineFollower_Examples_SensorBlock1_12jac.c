/* Jacobians */
#include "LineFollower_Examples_SensorBlock1_model.h"
#include "LineFollower_Examples_SensorBlock1_12jac.h"

int LineFollower_Examples_SensorBlock1_initialAnalyticJacobianD(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = LineFollower_Examples_SensorBlock1_INDEX_JAC_D;
  const int tmp[4] = {1,1,1,0};
  const int tmpElem[3] = {0,0,0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 4;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 0;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(4,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc(4*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(3*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(4*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 3;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, tmp, 4*sizeof(int));
  
  for(i=1;i<4;++i)
      data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, tmpElem, 3*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 3;
  TRACE_POP
  return 0;
}
int LineFollower_Examples_SensorBlock1_initialAnalyticJacobianC(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int LineFollower_Examples_SensorBlock1_initialAnalyticJacobianB(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int LineFollower_Examples_SensorBlock1_initialAnalyticJacobianA(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}

int LineFollower_Examples_SensorBlock1_functionJacD_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = LineFollower_Examples_SensorBlock1_INDEX_JAC_D;
  
  TRACE_POP
  return 0;
}
int LineFollower_Examples_SensorBlock1_functionJacC_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int LineFollower_Examples_SensorBlock1_functionJacB_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int LineFollower_Examples_SensorBlock1_functionJacA_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}


