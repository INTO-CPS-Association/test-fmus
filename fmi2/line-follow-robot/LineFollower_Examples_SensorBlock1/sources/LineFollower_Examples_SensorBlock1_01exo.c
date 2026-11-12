/* External objects file */
#include "LineFollower_Examples_SensorBlock1_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Has to be performed after _init.xml file has been read */
void LineFollower_Examples_SensorBlock1_callExternalObjectConstructors(DATA *data, threadData_t *threadData)
{
  static const MMC_DEFSTRINGLIT(tmp2,3,"map");
  static const MMC_DEFSTRINGLIT(tmp3,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp4,6,"NoName");
  real_array tmp5;
  /* data->simulationInfo->extObjs = NULL; */
  infoStreamPrint(LOG_DEBUG, 0, "call external Object Constructors");
  alloc_real_array(&tmp5, 2, 0, 1);
  data->simulationInfo->extObjs[0] /* sensor1._combitable2d1._tableID EXTOBJ: Modelica.Blocks.Types.ExternalCombiTable2D */ = omc_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData, MMC_REFSTRINGLIT(tmp2), (((!stringEqual(data->simulationInfo->stringParameter[0] /* sensor1._combitable2d1._fileName PARAM */, MMC_REFSTRINGLIT(tmp3))) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[0] /* sensor1._combitable2d1._fileName PARAM */)))?data->simulationInfo->stringParameter[0] /* sensor1._combitable2d1._fileName PARAM */:MMC_REFSTRINGLIT(tmp4)), tmp5, 1);
  infoStreamPrint(LOG_DEBUG, 0, "call external Object Constructors finished");
}

void LineFollower_Examples_SensorBlock1_callExternalObjectDestructors(DATA *data, threadData_t *threadData)
{
  if(data->simulationInfo->extObjs)
  {
    omc_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData,data->simulationInfo->extObjs[0] /* sensor1._combitable2d1._tableID EXTOBJ: Modelica.Blocks.Types.ExternalCombiTable2D */);
    free(data->simulationInfo->extObjs);
    data->simulationInfo->extObjs = 0;
  }
}
#if defined(__cplusplus)
}
#endif

