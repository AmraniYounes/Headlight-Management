/*
 * File: Actuator.c
 *
 * Code generated for Simulink model 'Actuator'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 29 02:19:25 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Actuator.h"

/* Model step function */
void Actuator_Step(void)
{
  /* Outport generated from: '<Root>/Bus Element Out1' incorporates:
   *  Inport generated from: '<Root>/Bus Element In1'
   *  SignalConversion generated from: '<Root>/DRL_Final_Outport_1'
   *
   * Block description for Inport generated from '<Root>/Bus Element In1':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Actuator_Step_DRL_Final_Value
    (Rte_IRead_Actuator_Step_DRL_Status_In_Value());

  /* Outport generated from: '<Root>/Bus Element Out2' incorporates:
   *  Inport generated from: '<Root>/Bus Element In2'
   *  SignalConversion generated from: '<Root>/LowBeam_Final_Outport_2'
   *
   * Block description for Inport generated from '<Root>/Bus Element In2':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Actuator_Step_LowBeam_Final_Value
    (Rte_IRead_Actuator_Step_LowBeam_Status_In_Value());

  /* Outport generated from: '<Root>/Bus Element Out3' incorporates:
   *  Inport generated from: '<Root>/Bus Element In3'
   *  SignalConversion generated from: '<Root>/HighBeam_Final_Outport_3'
   *
   * Block description for Inport generated from '<Root>/Bus Element In3':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Actuator_Step_HighBeam_Final_Value
    (Rte_IRead_Actuator_Step_HighBeam_Status_In_Value());

  /* Outport generated from: '<Root>/Bus Element Out4' incorporates:
   *  Inport generated from: '<Root>/Bus Element In4'
   *  SignalConversion generated from: '<Root>/TurnRight_Final_Outport_4'
   *
   * Block description for Inport generated from '<Root>/Bus Element In4':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Actuator_Step_TurnRight_Final_Value
    (Rte_IRead_Actuator_Step_TurnRight_Status_In_Value());

  /* Outport generated from: '<Root>/Bus Element Out5' incorporates:
   *  Inport generated from: '<Root>/Bus Element In5'
   *  SignalConversion generated from: '<Root>/TurnLeft_Final_Outport_5'
   *
   * Block description for Inport generated from '<Root>/Bus Element In5':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Actuator_Step_TurnLeft_Final_Value
    (Rte_IRead_Actuator_Step_TurnLeft_Status_In_Value());

  /* Outport generated from: '<Root>/Bus Element Out6' incorporates:
   *  Inport generated from: '<Root>/Bus Element In6'
   *  SignalConversion generated from: '<Root>/FogLight_Final_Outport_6'
   *
   * Block description for Inport generated from '<Root>/Bus Element In6':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Actuator_Step_FogLight_Final_Value
    (Rte_IRead_Actuator_Step_FogLight_Status_In_Value());
}

/* Model initialize function */
void Actuator_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
