/*
 * File: AutomaticFog_Detector.h
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

#ifndef AutomaticFog_Detector_h_
#define AutomaticFog_Detector_h_
#ifndef AutomaticFog_Detector_COMMON_INCLUDES_
#define AutomaticFog_Detector_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_AutomaticFog_Detector.h"
#endif                              /* AutomaticFog_Detector_COMMON_INCLUDES_ */

#include "AutomaticFog_Detector_types.h"
#include "Rte_Type.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 Humidity_MinVal;               /* '<Root>/Data Store Memory' */
  uint8 Visibility_MinVal;             /* '<Root>/Data Store Memory1' */
} ARID_DEF_AutomaticFog_Detecto_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_AutomaticFog_Detecto_T AutomaticFog_Detector_ARID_DEF;/* '<Root>/Data Store Memory' */

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
 * '<Root>' : 'AutomaticFog_Detector'
 * '<S1>'   : 'AutomaticFog_Detector/AF_Sensor_Check'
 * '<S2>'   : 'AutomaticFog_Detector/BoolToEventStatus'
 * '<S3>'   : 'AutomaticFog_Detector/Initialize Function'
 * '<S4>'   : 'AutomaticFog_Detector/AF_Sensor_Check/Humidity_Check'
 * '<S5>'   : 'AutomaticFog_Detector/AF_Sensor_Check/Visibility_Check'
 */
#endif                                 /* AutomaticFog_Detector_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
