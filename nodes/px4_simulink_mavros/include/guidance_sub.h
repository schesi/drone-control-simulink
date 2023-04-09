//
// File: guidance_sub.h
//
// Code generated for Simulink model 'guidance_sub'.
//
// Model version                  : 1.48
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Mon Nov 14 20:12:23 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_guidance_sub_h_
#define RTW_HEADER_guidance_sub_h_
#include <cmath>
#include <string.h>
#include <stddef.h>
#ifndef guidance_sub_COMMON_INCLUDES_
# define guidance_sub_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // guidance_sub_COMMON_INCLUDES_

#include "guidance_sub_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T j;                            // '<Root>/guidance_function'
  real_T found_target;                 // '<Root>/guidance_function'
  real_T target_pos[3];                // '<Root>/guidance_function'
} DW_guidance_sub_T;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T pos_xyz[3];                   // '<Root>/pos_xyz'
  real_T vel_xyz[3];                   // '<Root>/vel_xyz'
  boolean_T flag_detect;               // '<Root>/flag_detect'
  real_T wps[6];                       // '<Root>/wps'
} ExtU_guidance_sub_T;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T target_pos_xyz[3];            // '<Root>/target_pos_xyz'
} ExtY_guidance_sub_T;

// Real-time Model Data Structure
struct tag_RTM_guidance_sub_T {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Class declaration for model guidance_sub
class guidance_subModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_guidance_sub_T guidance_sub_U;

  // External outputs
  ExtY_guidance_sub_T guidance_sub_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  guidance_subModelClass();

  // Destructor
  ~guidance_subModelClass();

  // Real-Time Model get method
  RT_MODEL_guidance_sub_T * getRTM();

  // private data and function members
 private:
  // Block states
  DW_guidance_sub_T guidance_sub_DW;

  // Real-Time Model
  RT_MODEL_guidance_sub_T guidance_sub_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'guidance_sub'
//  '<S1>'   : 'guidance_sub/guidance_function'

#endif                                 // RTW_HEADER_guidance_sub_h_

//
// File trailer for generated code.
//
// [EOF]
//
