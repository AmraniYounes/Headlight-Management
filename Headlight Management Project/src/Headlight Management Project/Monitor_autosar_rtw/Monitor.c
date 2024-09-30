/*
 * File: Monitor.c
 *
 * Code generated for Simulink model 'Monitor'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 29 02:26:14 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Monitor.h"
#include "Platform_Types.h"
#include "Rte_Type.h"

/* Model step function */
void Monitor_Step(void)
{
  Dem_EventStatusType tmp;
  uint8 rtb_BitwiseAND;
  boolean rtb_CastToBoolean;
  boolean rtb_Switch;

  /* FunctionCaller: '<S4>/DiagnosticInfoCaller' */
  Rte_Call_N_Detector_GetEventUdsStatus(&rtb_BitwiseAND);

  /* FunctionCaller: '<S1>/DiagnosticInfoCaller' incorporates:
   *  S-Function (sfix_bitop): '<S4>/Bitwise AND'
   */
  rtb_BitwiseAND &= 1;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  DataTypeConversion: '<S4>/Cast To Boolean'
   */
  if (rtb_BitwiseAND != 0) {
    tmp = DEM_EVENT_STATUS_FAILED;
  } else {
    tmp = DEM_EVENT_STATUS_PASSED;
  }

  /* End of Switch: '<S2>/Switch' */

  /* FunctionCaller: '<Root>/N_Detector_Down_or_Up' */
  Rte_Call_Night_Sensor_SetEventStatus(tmp);

  /* Switch: '<Root>/Switch' incorporates:
   *  DataTypeConversion: '<S4>/Cast To Boolean'
   *  Inport generated from: '<Root>/Bus Element In1'
   */
  rtb_Switch = ((rtb_BitwiseAND == 0) &&
                Rte_IRead_Monitor_Step_N_Detector_In_Value());

  /* FunctionCaller: '<S1>/DiagnosticInfoCaller' */
  Rte_Call_AF_Detector_GetEventUdsStatus(&rtb_BitwiseAND);

  /* DataTypeConversion: '<S1>/Cast To Boolean' incorporates:
   *  S-Function (sfix_bitop): '<S1>/Bitwise AND'
   */
  rtb_CastToBoolean = ((rtb_BitwiseAND & 1U) != 0U);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   */
  if (rtb_CastToBoolean) {
    tmp = DEM_EVENT_STATUS_FAILED;
  } else {
    tmp = DEM_EVENT_STATUS_PASSED;
  }

  /* End of Switch: '<S3>/Switch' */

  /* FunctionCaller: '<Root>/AF_Detector_Down_or_Up' */
  Rte_Call_AutoFogLight_Sensor_SetEventStatus(tmp);

  /* Outport generated from: '<Root>/Bus Element Out1'
   *
   * Block description for Outport generated from '<Root>/Bus Element Out1':
   *  Sensors detection output values:
   *  0: nothing detected
   *  1: night or fog detected
   */
  Rte_IWrite_Monitor_Step_N_Detector_Out_Value(rtb_Switch);

  /* Outport generated from: '<Root>/Bus Element Out2' incorporates:
   *  Inport generated from: '<Root>/Bus Element In2'
   *  Switch: '<Root>/Switch1'
   *
   * Block description for Outport generated from '<Root>/Bus Element Out2':
   *  Sensors detection output values:
   *  0: nothing detected
   *  1: night or fog detected
   */
  Rte_IWrite_Monitor_Step_AF_Detector_Out_Value((!rtb_CastToBoolean) &&
    Rte_IRead_Monitor_Step_AF_Detector_In_Value());
}

/* Model initialize function */
void Monitor_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
