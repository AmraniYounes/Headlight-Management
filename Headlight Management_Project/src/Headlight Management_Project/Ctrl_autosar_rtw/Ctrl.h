/*
 * File: Ctrl.h
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

#ifndef Ctrl_h_
#define Ctrl_h_
#ifndef Ctrl_COMMON_INCLUDES_
#define Ctrl_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Ctrl.h"
#endif                                 /* Ctrl_COMMON_INCLUDES_ */

#include "Ctrl_types.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 is_c1_Ctrl;                    /* '<Root>/Turn Signals chart' */
  uint8 temporalCounter_i1;            /* '<Root>/Turn Signals chart' */
  uint8 is_c3_Ctrl;                    /* '<Root>/Headlamps chart' */
  uint8 is_Lighting_Level;             /* '<Root>/Headlamps chart' */
  uint8 is_c2_Ctrl;                    /* '<Root>/Fog Lights chart' */
} ARID_DEF_Ctrl_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_Ctrl_T Ctrl_ARID_DEF;  /* '<Root>/Turn Signals chart' */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Ctrl'
 * '<S1>'   : 'Ctrl/Fog Lights chart'
 * '<S2>'   : 'Ctrl/Headlamps chart'
 * '<S3>'   : 'Ctrl/Turn Signals chart'
 */
#endif                                 /* Ctrl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
