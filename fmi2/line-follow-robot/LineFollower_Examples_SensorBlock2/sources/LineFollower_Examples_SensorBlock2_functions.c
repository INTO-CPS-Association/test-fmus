#include "LineFollower_Examples_SensorBlock2_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "LineFollower_Examples_SensorBlock2_includes.h"


DLLExport
modelica_string omc_LineFollower_Components_Sensor$sensor1_getResource(threadData_t *threadData)
{
  modelica_string _r = NULL;
  modelica_string _s = NULL;
  _tailrecursive: OMC_LABEL_UNUSED
  _s = _OMC_LIT0;

  _r = _s;
  _return: OMC_LABEL_UNUSED
  return _r;
}

modelica_real omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue(threadData_t *threadData, modelica_complex _tableID, modelica_real _u1, modelica_real _u2, modelica_real _tableAvailable)
{
  void * _tableID_ext;
  double _u1_ext;
  double _u2_ext;
  double _y_ext;
  modelica_real _y;
  _tableID_ext = (void *)_tableID;
  _u1_ext = (double)_u1;
  _u2_ext = (double)_u2;
  _y_ext = ModelicaStandardTables_CombiTable2D_getValue(_tableID_ext, _u1_ext, _u2_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _u1, modelica_metatype _u2, modelica_metatype _tableAvailable)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_u1);
  tmp2 = mmc_unbox_real(_u2);
  tmp3 = mmc_unbox_real(_tableAvailable);
  _y = omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue(threadData, _tableID, tmp1, tmp2, tmp3);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

modelica_real omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData(threadData_t *threadData, modelica_complex _tableID, modelica_boolean _forceRead, modelica_boolean _verboseRead)
{
  void * _tableID_ext;
  int _forceRead_ext;
  int _verboseRead_ext;
  double _readSuccess_ext;
  modelica_real _readSuccess;
  _tableID_ext = (void *)_tableID;
  _forceRead_ext = (int)_forceRead;
  _verboseRead_ext = (int)_verboseRead;
  _readSuccess_ext = ModelicaStandardTables_CombiTable2D_read(_tableID_ext, _forceRead_ext, _verboseRead_ext);
  _readSuccess = (modelica_real)_readSuccess_ext;
  return _readSuccess;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _forceRead, modelica_metatype _verboseRead)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_real _readSuccess;
  modelica_metatype out_readSuccess;
  tmp1 = mmc_unbox_integer(_forceRead);
  tmp2 = mmc_unbox_integer(_verboseRead);
  _readSuccess = omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData(threadData, _tableID, tmp1, tmp2);
  out_readSuccess = mmc_mk_rcon(_readSuccess);
  return out_readSuccess;
}

modelica_complex omc_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData_t *threadData, modelica_string _tableName, modelica_string _fileName, real_array _table, modelica_integer _smoothness)
{
  int _smoothness_ext;
  void *_table_c89;
  void * _externalCombiTable2D_ext;
  modelica_complex _externalCombiTable2D;
  _smoothness_ext = (int)_smoothness;_table_c89 = (void*) data_of_real_c89_array(&(_table));
  _externalCombiTable2D_ext = ModelicaStandardTables_CombiTable2D_init(MMC_STRINGDATA(_tableName), MMC_STRINGDATA(_fileName), (const double*) _table_c89, size_of_dimension_base_array(_table, ((modelica_integer) 1)), size_of_dimension_base_array(_table, ((modelica_integer) 2)), _smoothness_ext);
  _externalCombiTable2D = (modelica_complex)_externalCombiTable2D_ext;
  return _externalCombiTable2D;
}
modelica_metatype boxptr_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData_t *threadData, modelica_metatype _tableName, modelica_metatype _fileName, modelica_metatype _table, modelica_metatype _smoothness)
{
  modelica_integer tmp1;
  modelica_complex _externalCombiTable2D;
  tmp1 = mmc_unbox_integer(_smoothness);
  _externalCombiTable2D = omc_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData, _tableName, _fileName, *((base_array_t*)_table), tmp1);
  /* skip box _externalCombiTable2D; ExternalObject Modelica.Blocks.Types.ExternalCombiTable2D */
  return _externalCombiTable2D;
}

void omc_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData_t *threadData, modelica_complex _externalCombiTable2D)
{
  void * _externalCombiTable2D_ext;
  _externalCombiTable2D_ext = (void *)_externalCombiTable2D;
  ModelicaStandardTables_CombiTable2D_close(_externalCombiTable2D_ext);
  return;
}
void boxptr_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData_t *threadData, modelica_metatype _externalCombiTable2D)
{
  omc_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData, _externalCombiTable2D);
  return;
}

DLLExport
modelica_boolean omc_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_string _string)
{
  modelica_boolean _result;
  modelica_integer _nextIndex;
  modelica_integer _len;
  _tailrecursive: OMC_LABEL_UNUSED
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, ((modelica_integer) 1));

  _len = omc_Modelica_Utilities_Strings_length(threadData, _string);

  if((((modelica_integer)_len < ((modelica_integer) 1)) || ((modelica_integer)_nextIndex > (modelica_integer)_len)))
  {
    _result = 1;
  }
  else
  {
    _result = 0;
  }
  _return: OMC_LABEL_UNUSED
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_metatype _string)
{
  modelica_boolean _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_Strings_isEmpty(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

modelica_integer omc_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_string _string)
{
  int _result_ext;
  modelica_integer _result;
  _result_ext = ModelicaStrings_length(MMC_STRINGDATA(_string));
  _result = (modelica_integer)_result_ext;
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_metatype _string)
{
  modelica_integer _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_Strings_length(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

modelica_integer omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex)
{
  int _startIndex_ext;
  int _nextIndex_ext;
  modelica_integer _nextIndex;
  _startIndex_ext = (int)_startIndex;
  _nextIndex_ext = ModelicaStrings_skipWhiteSpace(MMC_STRINGDATA(_string), _startIndex_ext);
  _nextIndex = (modelica_integer)_nextIndex_ext;
  return _nextIndex;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex)
{
  modelica_integer tmp1;
  modelica_integer _nextIndex;
  modelica_metatype out_nextIndex;
  tmp1 = mmc_unbox_integer(_startIndex);
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, tmp1);
  out_nextIndex = mmc_mk_icon(_nextIndex);
  return out_nextIndex;
}

#ifdef __cplusplus
}
#endif
