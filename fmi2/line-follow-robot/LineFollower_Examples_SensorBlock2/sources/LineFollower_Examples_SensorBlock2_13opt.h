#if defined(__cplusplus)
  extern "C" {
#endif
  int LineFollower_Examples_SensorBlock2_mayer(DATA* data, modelica_real** res, short*);
  int LineFollower_Examples_SensorBlock2_lagrange(DATA* data, modelica_real** res, short *, short *);
  int LineFollower_Examples_SensorBlock2_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int LineFollower_Examples_SensorBlock2_setInputData(DATA *data, const modelica_boolean file);
  int LineFollower_Examples_SensorBlock2_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif