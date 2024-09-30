/*
 * File: Night_Detector.h
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

#ifndef Night_Detector_h_
#define Night_Detector_h_
#ifndef Night_Detector_COMMON_INCLUDES_
#define Night_Detector_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_Night_Detector.h"
#endif                                 /* Night_Detector_COMMON_INCLUDES_ */

#include "Night_Detector_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint16 Light_MinVal;                 /* '<Root>/Data Store Memory' */
} ARID_DEF_Night_Detector_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_Night_Detector_T Night_Detector_ARID_DEF;/* '<Root>/Data Store Memory' */

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
 * '<Root>' : 'Night_Detector'
 * '<S1>'   : 'Night_Detector/BoolToEventStatus'
 * '<S2>'   : 'Night_Detector/Initialize Function'
 * '<S3>'   : 'Night_Detector/N_Detector_Check'
 */
#endif                                 /* Night_Detector_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
