/*
 * File: Ctrl.c
 *
 * Code generated for Simulink model 'Ctrl'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Sep 29 02:19:59 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ctrl.h"
#include "Platform_Types.h"

/* Named constants for Chart: '<Root>/Fog Lights chart' */
#define Ctrl_IN_FogLight_Active_State  ((uint8)1U)
#define Ctrl_IN_Idle_State             ((uint8)2U)

/* Named constants for Chart: '<Root>/Headlamps chart' */
#define Ctrl_IN_HighBeam_Active_State  ((uint8)2U)
#define Ctrl_IN_Idle_State_a           ((uint8)1U)
#define Ctrl_IN_Lighting_Level         ((uint8)2U)
#define Ctrl_IN_LowBeam_Active_State   ((uint8)3U)
#define IN_DayRunningLights_Active_Stat ((uint8)1U)

/* Named constants for Chart: '<Root>/Turn Signals chart' */
#define Ctrl_IN_Blink_State            ((uint8)1U)
#define Ctrl_IN_Blink_State1           ((uint8)2U)
#define Ctrl_IN_TurnLeft_Active_State  ((uint8)3U)
#define Ctrl_IN_TurnLights_Idle_State  ((uint8)4U)
#define Ctrl_IN_TurnRight_Active_State ((uint8)5U)

/* PublicStructure Variables for Internal Data */
ARID_DEF_Ctrl_T Ctrl_ARID_DEF;         /* '<Root>/Turn Signals chart' */

/* Model step function */
void Ctrl_Step(void)
{
  sint32 tmp_0;
  boolean DRL_Status_Out;
  boolean FogLight_Status_Out;
  boolean HighBeam_Status_Out;
  boolean LowBeam_Status_Out;
  boolean TurnLeft_Status_Out;
  boolean TurnRight_Status_Out;
  boolean tmp;

  /* Chart: '<Root>/Fog Lights chart' incorporates:
   *  Inport generated from: '<Root>/Bus Element In3'
   *  Inport generated from: '<Root>/Bus Element In1'
   *
   * Block description for Inport generated from '<Root>/Bus Element In3':
   *  Sensors detection output values:
   *  0: nothing detected
   *  1: night or fog detected
   *
   * Block description for Inport generated from '<Root>/Bus Element In1':
   *  Ignition State:
   *  0: OFF
   *  1: ON
   */
  FogLight_Status_Out = FALSE;
  if (Ctrl_ARID_DEF.is_c2_Ctrl == Ctrl_IN_FogLight_Active_State) {
    if ((!Rte_IRead_Ctrl_Step_Ignition_State_Value()) ||
        (!Rte_IRead_Ctrl_Step_AF_Detector_Out_Value())) {
      Ctrl_ARID_DEF.is_c2_Ctrl = Ctrl_IN_Idle_State;
    }
  } else {
    /* case IN_Idle_State: */
    tmp = Rte_IRead_Ctrl_Step_Ignition_State_Value();
    if (!tmp) {
      Ctrl_ARID_DEF.is_c2_Ctrl = Ctrl_IN_Idle_State;
    } else if (tmp && Rte_IRead_Ctrl_Step_AF_Detector_Out_Value()) {
      Ctrl_ARID_DEF.is_c2_Ctrl = Ctrl_IN_FogLight_Active_State;
      FogLight_Status_Out = TRUE;
    }
  }

  /* End of Chart: '<Root>/Fog Lights chart' */

  /* Chart: '<Root>/Headlamps chart' incorporates:
   *  Inport generated from: '<Root>/Bus Element In5'
   *  Inport generated from: '<Root>/Bus Element In1'
   *  Inport generated from: '<Root>/Bus Element In2'
   *
   * Block description for Inport generated from '<Root>/Bus Element In1':
   *  Ignition State:
   *  0: OFF
   *  1: ON
   *
   * Block description for Inport generated from '<Root>/Bus Element In2':
   *  Sensors detection output values:
   *  0: nothing detected
   *  1: night or fog detected
   */
  DRL_Status_Out = FALSE;
  LowBeam_Status_Out = FALSE;
  HighBeam_Status_Out = FALSE;
  if (Ctrl_ARID_DEF.is_c3_Ctrl == Ctrl_IN_Idle_State_a) {
    if (Rte_IRead_Ctrl_Step_Ignition_State_Value()) {
      Ctrl_ARID_DEF.is_c3_Ctrl = Ctrl_IN_Lighting_Level;
      Ctrl_ARID_DEF.is_Lighting_Level = IN_DayRunningLights_Active_Stat;
      DRL_Status_Out = TRUE;
    }

    /* case IN_Lighting_Level: */
  } else if (!Rte_IRead_Ctrl_Step_Ignition_State_Value()) {
    Ctrl_ARID_DEF.is_Lighting_Level = 0;
    Ctrl_ARID_DEF.is_c3_Ctrl = Ctrl_IN_Idle_State_a;
  } else {
    switch (Ctrl_ARID_DEF.is_Lighting_Level) {
     case IN_DayRunningLights_Active_Stat:
      if (Rte_IRead_Ctrl_Step_N_Detector_Out_Value()) {
        Ctrl_ARID_DEF.is_Lighting_Level = Ctrl_IN_LowBeam_Active_State;
        LowBeam_Status_Out = TRUE;
      }
      break;

     case Ctrl_IN_HighBeam_Active_State:
      if (Rte_IRead_Ctrl_Step_HighBeam_Cmd_Value() != 1) {
        Ctrl_ARID_DEF.is_Lighting_Level = Ctrl_IN_LowBeam_Active_State;
        LowBeam_Status_Out = TRUE;
      } else if (!Rte_IRead_Ctrl_Step_N_Detector_Out_Value()) {
        Ctrl_ARID_DEF.is_Lighting_Level = IN_DayRunningLights_Active_Stat;
        DRL_Status_Out = TRUE;
      }
      break;

     default:
      /* case IN_LowBeam_Active_State: */
      if (Rte_IRead_Ctrl_Step_HighBeam_Cmd_Value() == 1) {
        Ctrl_ARID_DEF.is_Lighting_Level = Ctrl_IN_HighBeam_Active_State;
        HighBeam_Status_Out = TRUE;
      } else if (!Rte_IRead_Ctrl_Step_N_Detector_Out_Value()) {
        Ctrl_ARID_DEF.is_Lighting_Level = IN_DayRunningLights_Active_Stat;
        DRL_Status_Out = TRUE;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Headlamps chart' */

  /* Chart: '<Root>/Turn Signals chart' incorporates:
   *  Inport generated from: '<Root>/Bus Element In1'
   *  Inport generated from: '<Root>/Bus Element In4'
   *
   * Block description for Inport generated from '<Root>/Bus Element In1':
   *  Ignition State:
   *  0: OFF
   *  1: ON
   */
  TurnLeft_Status_Out = FALSE;
  TurnRight_Status_Out = FALSE;
  if (Ctrl_ARID_DEF.temporalCounter_i1 < 3U) {
    Ctrl_ARID_DEF.temporalCounter_i1++;
  }

  switch (Ctrl_ARID_DEF.is_c1_Ctrl) {
   case Ctrl_IN_Blink_State:
    if (Ctrl_ARID_DEF.temporalCounter_i1 >= 2) {
      Ctrl_ARID_DEF.temporalCounter_i1 = 0U;
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnRight_Active_State;
      TurnRight_Status_Out = TRUE;
    } else if (!Rte_IRead_Ctrl_Step_Ignition_State_Value()) {
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnLights_Idle_State;
    } else if (Rte_IRead_Ctrl_Step_TurnSignal_Cmd_Value() == 2) {
      Ctrl_ARID_DEF.temporalCounter_i1 = 0U;
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_Blink_State1;
      TurnLeft_Status_Out = TRUE;
    }
    break;

   case Ctrl_IN_Blink_State1:
    if (!Rte_IRead_Ctrl_Step_Ignition_State_Value()) {
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnLights_Idle_State;
    } else if (Ctrl_ARID_DEF.temporalCounter_i1 >= 2) {
      Ctrl_ARID_DEF.temporalCounter_i1 = 0U;
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnLeft_Active_State;
      TurnLeft_Status_Out = TRUE;
    } else if (Rte_IRead_Ctrl_Step_TurnSignal_Cmd_Value() == 1) {
      Ctrl_ARID_DEF.temporalCounter_i1 = 0U;
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_Blink_State;
      TurnRight_Status_Out = TRUE;
    }
    break;

   case Ctrl_IN_TurnLeft_Active_State:
    if (Rte_IRead_Ctrl_Step_Ignition_State_Value() &&
        (Rte_IRead_Ctrl_Step_TurnSignal_Cmd_Value() == 0)) {
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnLights_Idle_State;
    } else if (Ctrl_ARID_DEF.temporalCounter_i1 >= 2) {
      Ctrl_ARID_DEF.temporalCounter_i1 = 0U;
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_Blink_State1;
      TurnLeft_Status_Out = TRUE;
    }
    break;

   case Ctrl_IN_TurnLights_Idle_State:
    tmp = Rte_IRead_Ctrl_Step_Ignition_State_Value();
    tmp_0 = Rte_IRead_Ctrl_Step_TurnSignal_Cmd_Value();
    if (tmp && (tmp_0 == 1)) {
      Ctrl_ARID_DEF.temporalCounter_i1 = 0U;
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnRight_Active_State;
      TurnRight_Status_Out = TRUE;
    } else if (tmp && (tmp_0 == 2)) {
      Ctrl_ARID_DEF.temporalCounter_i1 = 0U;
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnLeft_Active_State;
      TurnLeft_Status_Out = TRUE;
    } else if (!tmp) {
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnLights_Idle_State;
    }
    break;

   default:
    /* case IN_TurnRight_Active_State: */
    if (Rte_IRead_Ctrl_Step_Ignition_State_Value() &&
        (Rte_IRead_Ctrl_Step_TurnSignal_Cmd_Value() == 0)) {
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnLights_Idle_State;
    } else if (Ctrl_ARID_DEF.temporalCounter_i1 >= 2) {
      Ctrl_ARID_DEF.temporalCounter_i1 = 0U;
      Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_Blink_State;
      TurnRight_Status_Out = TRUE;
    }
    break;
  }

  /* End of Chart: '<Root>/Turn Signals chart' */

  /* Outport generated from: '<Root>/Bus Element Out1'
   *
   * Block description for Outport generated from '<Root>/Bus Element Out1':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Ctrl_Step_DRL_Status_Out_Value(DRL_Status_Out);

  /* Outport generated from: '<Root>/Bus Element Out2'
   *
   * Block description for Outport generated from '<Root>/Bus Element Out2':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Ctrl_Step_LowBeam_Status_Out_Value(LowBeam_Status_Out);

  /* Outport generated from: '<Root>/Bus Element Out3'
   *
   * Block description for Outport generated from '<Root>/Bus Element Out3':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Ctrl_Step_HighBeam_Status_Out_Value(HighBeam_Status_Out);

  /* Outport generated from: '<Root>/Bus Element Out4'
   *
   * Block description for Outport generated from '<Root>/Bus Element Out4':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Ctrl_Step_TurnRight_Status_Out_Value(TurnRight_Status_Out);

  /* Outport generated from: '<Root>/Bus Element Out5'
   *
   * Block description for Outport generated from '<Root>/Bus Element Out5':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Ctrl_Step_TurnLeft_Status_Out_Value(TurnLeft_Status_Out);

  /* Outport generated from: '<Root>/Bus Element Out6'
   *
   * Block description for Outport generated from '<Root>/Bus Element Out6':
   *  Lights state On or OFF (LowBeam, HighBeam, DRL, FogLight, ...):
   *  0: Light should be OFF
   *  1: Light should be ON
   */
  Rte_IWrite_Ctrl_Step_FogLight_Status_Out_Value(FogLight_Status_Out);
}

/* Model initialize function */
void Ctrl_Init(void)
{
  /* Chart: '<Root>/Fog Lights chart' */
  Ctrl_ARID_DEF.is_c2_Ctrl = Ctrl_IN_Idle_State;

  /* Chart: '<Root>/Headlamps chart' */
  Ctrl_ARID_DEF.is_c3_Ctrl = Ctrl_IN_Idle_State_a;

  /* Chart: '<Root>/Turn Signals chart' */
  Ctrl_ARID_DEF.is_c1_Ctrl = Ctrl_IN_TurnLights_Idle_State;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
