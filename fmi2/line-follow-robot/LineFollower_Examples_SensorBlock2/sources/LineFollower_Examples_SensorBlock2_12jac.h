/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define LineFollower_Examples_SensorBlock2_INDEX_JAC_D 3
  int LineFollower_Examples_SensorBlock2_functionJacD_column(void* data, threadData_t *threadData);
  int LineFollower_Examples_SensorBlock2_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */
#define $Probot_thetaSeedD data->simulationInfo->analyticJacobians[3].seedVars[0]
#define $Probot_xSeedD data->simulationInfo->analyticJacobians[3].seedVars[1]
#define $Probot_ySeedD data->simulationInfo->analyticJacobians[3].seedVars[2]
#define $Probot_zSeedD data->simulationInfo->analyticJacobians[3].seedVars[3]

#if defined(__cplusplus)
extern "C" {
#endif
  #define LineFollower_Examples_SensorBlock2_INDEX_JAC_C 2
  int LineFollower_Examples_SensorBlock2_functionJacC_column(void* data, threadData_t *threadData);
  int LineFollower_Examples_SensorBlock2_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define LineFollower_Examples_SensorBlock2_INDEX_JAC_B 1
  int LineFollower_Examples_SensorBlock2_functionJacB_column(void* data, threadData_t *threadData);
  int LineFollower_Examples_SensorBlock2_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define LineFollower_Examples_SensorBlock2_INDEX_JAC_A 0
  int LineFollower_Examples_SensorBlock2_functionJacA_column(void* data, threadData_t *threadData);
  int LineFollower_Examples_SensorBlock2_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */


