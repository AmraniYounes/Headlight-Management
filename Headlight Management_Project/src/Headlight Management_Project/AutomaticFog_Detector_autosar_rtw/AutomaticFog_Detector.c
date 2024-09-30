/*
 * File: AutomaticFog_Detector.c
 *
 * Code generated for Simulink model 'AutomaticFog_Detector'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 29 02:23:31 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AutomaticFog_Detector.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_AutomaticFog_Detecto_T AutomaticFog_Detector_ARID_DEF;/* '<Root>/Data Store Memory' */

/* Model step function */
void AutomaticFog_Detector_Step(void)
{
  sint32 tmp_0;
  uint16 tmp_1;
  Dem_EventStatusType tmp;

  /* RelationalOperator: '<S4>/Less Than' incorporates:
   *  Inport generated from: '<Root>/Bus Element In2'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<S4>/Less Than1'
   */
  tmp_0 = Rte_IRead_AutomaticFog_Detector_Step_Humidity_Data_Value();

  /* RelationalOperator: '<S5>/Less Than2' incorporates:
   *  Inport generated from: '<Root>/Bus Element In1'
   *  RelationalOperator: '<S5>/Less Than3'
   */
  tmp_1 = Rte_IRead_AutomaticFog_Detector_Step_Visibility_Distance_Value();

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  DataStoreRead: '<S4>/Data Store Read'
   *  DataStoreRead: '<S5>/Data Store Read1'
   *  Inport generated from: '<Root>/Bus Element In1'
   *  Logic: '<S1>/Logical Operator2'
   *  RelationalOperator: '<S4>/Less Than'
   *  RelationalOperator: '<S4>/Less Than1'
   *  RelationalOperator: '<S5>/Less Than2'
   *  RelationalOperator: '<S5>/Less Than3'
   */
  if ((tmp_0 < AutomaticFog_Detector_ARID_DEF.Humidity_MinVal) || (tmp_0 > 100) ||
      (tmp_1 < AutomaticFog_Detector_ARID_DEF.Visibility_MinVal) || (tmp_1 > 300))
  {
    tmp = DEM_EVENT_STATUS_PREFAILED;
  } else {
    tmp = DEM_EVENT_STATUS_PASSED;
  }

  /* End of Switch: '<S2>/Switch' */

  /* FunctionCaller: '<Root>/AF_Sensor_Status' */
  Rte_Call_AF_Detector_SetEventStatus(tmp);

  /* Outport generated from: '<Root>/Bus Element Out1' incorporates:
   *  Inport generated from: '<Root>/Bus Element In3'
   *  Logic: '<Root>/Logical Operator'
   *  Logic: '<Root>/Logical Operator1'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<Root>/Relational Operator1'
   *
   * Block description for Inport generated from '<Root>/Bus Element In3':
   *  Ignition State:
   *  0: OFF
   *  1: ON
   */
  Rte_IWrite_AutomaticFog_Detector_Step_AF_Detector_In_Value
    (Rte_IRead_AutomaticFog_Detector_Step_Ignition_State_Value() && (tmp_0 > 90)
     && (tmp_1 < 50));
}

/* Model initialize function */
void AutomaticFog_Detector_Init(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* FunctionCaller: '<S3>/NvMServiceCaller' */
  Rte_Call_Humidity_MinVal_ReadBlock
    (&AutomaticFog_Detector_ARID_DEF.Humidity_MinVal);

  /* FunctionCaller: '<S3>/NvMServiceCaller1' */
  Rte_Call_Visibility_MinVal_ReadBlock
    (&AutomaticFog_Detector_ARID_DEF.Visibility_MinVal);

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
