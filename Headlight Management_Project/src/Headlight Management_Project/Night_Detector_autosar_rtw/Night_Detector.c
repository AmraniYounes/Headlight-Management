/*
 * File: Night_Detector.c
 *
 * Code generated for Simulink model 'Night_Detector'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 29 02:29:02 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Night_Detector.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_Night_Detector_T Night_Detector_ARID_DEF;/* '<Root>/Data Store Memory' */

/* Model step function */
void Night_Detector_Step(void)
{
  sint32 tmp_0;
  Dem_EventStatusType tmp;

  /* RelationalOperator: '<S3>/Less Than' incorporates:
   *  Inport generated from: '<Root>/Bus Element In1'
   *  RelationalOperator: '<Root>/Relational Operator'
   *  RelationalOperator: '<S3>/Less Than1'
   */
  tmp_0 = Rte_IRead_Night_Detector_Step_Light_Data_Value();

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  DataStoreRead: '<S3>/Data Store Read'
   *  Logic: '<Root>/Logical Operator2'
   *  RelationalOperator: '<S3>/Less Than'
   *  RelationalOperator: '<S3>/Less Than1'
   */
  if ((tmp_0 < Night_Detector_ARID_DEF.Light_MinVal) || (tmp_0 > 64000)) {
    tmp = DEM_EVENT_STATUS_PREFAILED;
  } else {
    tmp = DEM_EVENT_STATUS_PASSED;
  }

  /* End of Switch: '<S1>/Switch' */

  /* FunctionCaller: '<Root>/N_Sensor_Status' */
  Rte_Call_N_Detector_SetEventStatus(tmp);

  /* Outport generated from: '<Root>/Bus Element Out1' incorporates:
   *  Constant: '<Root>/Light_Threshold'
   *  Inport generated from: '<Root>/Bus Element In2'
   *  Logic: '<Root>/Logical Operator'
   *  Logic: '<Root>/Logical Operator1'
   *  RelationalOperator: '<Root>/Relational Operator'
   *
   * Block description for Inport generated from '<Root>/Bus Element In2':
   *  Ignition State:
   *  0: OFF
   *  1: ON
   */
  Rte_IWrite_Night_Detector_Step_N_Detector_In_Value
    (Rte_IRead_Night_Detector_Step_Ignition_State_Value() && (tmp_0 < 300));
}

/* Model initialize function */
void Night_Detector_Init(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* FunctionCaller: '<S2>/Read_MinVal' */
  Rte_Call_Light_MinVal_ReadBlock(&Night_Detector_ARID_DEF.Light_MinVal);

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
