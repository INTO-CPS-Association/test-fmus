#ifndef LineFollower_Examples_SensorBlock1__H
#define LineFollower_Examples_SensorBlock1__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif


DLLExport
modelica_string omc_LineFollower_Components_Sensor$sensor1_getResource(threadData_t *threadData);
#define boxptr_LineFollower_Components_Sensor$sensor1_getResource omc_LineFollower_Components_Sensor$sensor1_getResource
static const MMC_DEFSTRUCTLIT(boxvar_lit_LineFollower_Components_Sensor$sensor1_getResource,2,0) {(void*) boxptr_LineFollower_Components_Sensor$sensor1_getResource,0}};
#define boxvar_LineFollower_Components_Sensor$sensor1_getResource MMC_REFSTRUCTLIT(boxvar_lit_LineFollower_Components_Sensor$sensor1_getResource)


modelica_real omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue(threadData_t *threadData, modelica_complex _tableID, modelica_real _u1, modelica_real _u2, modelica_real _tableAvailable);
modelica_metatype boxptr_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _u1, modelica_metatype _u2, modelica_metatype _tableAvailable);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue,2,0) {(void*) boxptr_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue,0}};
#define boxvar_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_getTableValue)
 /* boxvar early */

extern double ModelicaStandardTables_CombiTable2D_getValue(void * /*_tableID*/, double /*_u1*/, double /*_u2*/);

modelica_real omc_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData(threadData_t *threadData, modelica_complex _tableID, modelica_boolean _forceRead, modelica_boolean _verboseRead);
modelica_metatype boxptr_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _forceRead, modelica_metatype _verboseRead);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData,2,0) {(void*) boxptr_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData,0}};
#define boxvar_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Tables_CombiTable2D$sensor1$combitable2d1_readTableData)
 /* boxvar early */

extern double ModelicaStandardTables_CombiTable2D_read(void * /*_tableID*/, int /*_forceRead*/, int /*_verboseRead*/);

DLLExport
modelica_complex omc_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData_t *threadData, modelica_string _tableName, modelica_string _fileName, real_array _table, modelica_integer _smoothness);
DLLExport
modelica_metatype boxptr_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData_t *threadData, modelica_metatype _tableName, modelica_metatype _fileName, modelica_metatype _table, modelica_metatype _smoothness);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Types_ExternalCombiTable2D_constructor,2,0) {(void*) boxptr_Modelica_Blocks_Types_ExternalCombiTable2D_constructor,0}};
#define boxvar_Modelica_Blocks_Types_ExternalCombiTable2D_constructor MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Types_ExternalCombiTable2D_constructor)

extern void * ModelicaStandardTables_CombiTable2D_init(const char* /*_tableName*/, const char* /*_fileName*/, const double* /*_table*/, size_t, size_t, int /*_smoothness*/);

DLLExport
void omc_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData_t *threadData, modelica_complex _externalCombiTable2D);
DLLExport
void boxptr_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData_t *threadData, modelica_metatype _externalCombiTable2D);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Types_ExternalCombiTable2D_destructor,2,0) {(void*) boxptr_Modelica_Blocks_Types_ExternalCombiTable2D_destructor,0}};
#define boxvar_Modelica_Blocks_Types_ExternalCombiTable2D_destructor MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Types_ExternalCombiTable2D_destructor)

extern void ModelicaStandardTables_CombiTable2D_close(void * /*_externalCombiTable2D*/);

DLLExport
modelica_boolean omc_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_string _string);
DLLExport
modelica_metatype boxptr_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_metatype _string);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_isEmpty,2,0) {(void*) boxptr_Modelica_Utilities_Strings_isEmpty,0}};
#define boxvar_Modelica_Utilities_Strings_isEmpty MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_isEmpty)


DLLExport
modelica_integer omc_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_string _string);
DLLExport
modelica_metatype boxptr_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_metatype _string);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_length,2,0) {(void*) boxptr_Modelica_Utilities_Strings_length,0}};
#define boxvar_Modelica_Utilities_Strings_length MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_length)

extern int ModelicaStrings_length(const char* /*_string*/);

DLLExport
modelica_integer omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex);
DLLExport
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_Advanced_skipWhiteSpace,2,0) {(void*) boxptr_Modelica_Utilities_Strings_Advanced_skipWhiteSpace,0}};
#define boxvar_Modelica_Utilities_Strings_Advanced_skipWhiteSpace MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Utilities_Strings_Advanced_skipWhiteSpace)

extern int ModelicaStrings_skipWhiteSpace(const char* /*_string*/, int /*_startIndex*/);
#include "LineFollower_Examples_SensorBlock1_model.h"


#ifdef __cplusplus
}
#endif
#endif

