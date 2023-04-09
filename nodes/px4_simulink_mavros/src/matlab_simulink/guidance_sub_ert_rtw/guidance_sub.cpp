//
// File: guidance_sub.cpp
//
// Code generated for Simulink model 'guidance_sub'.
//
// Model version                  : 1.49
// Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
// C/C++ source code generated on : Mon Dec 26 12:55:21 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "guidance_sub.h"
#include "guidance_sub_private.h"

// Model step function
void guidance_subModelClass::step()
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T tmp;
  int32_T tmp_0;
  real_T rtb_next_wps_idx_0;
  real_T rtb_next_wps_idx_1;
  real_T rtb_next_wps_idx_2;

  // MATLAB Function: '<Root>/guidance_function' incorporates:
  //   Inport: '<Root>/flag_detect'
  //   Inport: '<Root>/pos_xyz'
  //   Inport: '<Root>/wps'

  // MATLAB Function 'guidance_function': '<S1>:1'
  // '<S1>:1:4' if isempty(target_pos)
  // '<S1>:1:10' next_wps = zeros(3,1);
  // '<S1>:1:11' if ~found_target
  if (!(guidance_sub_DW.found_target != 0.0)) {
    // '<S1>:1:12' next_wps = wps(1:3,j);
    tmp = (int32_T)guidance_sub_DW.j;

    //  go between wps
    // '<S1>:1:15' if norm(pos_xyz-next_wps) < 1
    tmp_0 = (int32_T)guidance_sub_DW.j;
    scale = 2.2250738585072014E-308;
    rtb_next_wps_idx_0 = guidance_sub_U.wps[(tmp - 1) * 3];
    absxk = std::abs(guidance_sub_U.pos_xyz[0] - guidance_sub_U.wps[(tmp_0 - 1) *
                     3]);
    if (absxk > 2.2250738585072014E-308) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 2.2250738585072014E-308;
      y = t * t;
    }

    rtb_next_wps_idx_1 = guidance_sub_U.wps[(tmp - 1) * 3 + 1];
    absxk = std::abs(guidance_sub_U.pos_xyz[1] - guidance_sub_U.wps[(tmp_0 - 1) *
                     3 + 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    rtb_next_wps_idx_2 = guidance_sub_U.wps[(tmp - 1) * 3 + 2];
    absxk = std::abs(guidance_sub_U.pos_xyz[2] - guidance_sub_U.wps[(tmp_0 - 1) *
                     3 + 2]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    y = scale * std::sqrt(y);
    if (y < 1.0) {
      // '<S1>:1:16' j = j+1;
      guidance_sub_DW.j++;

      // '<S1>:1:17' if j > 2
      if (guidance_sub_DW.j > 2.0) {
        // '<S1>:1:18' j=1;
        guidance_sub_DW.j = 1.0;
      }
    }

    //  stop there
    // '<S1>:1:24' if flag_detect
    if (guidance_sub_U.flag_detect) {
      // '<S1>:1:25' found_target = 1;
      guidance_sub_DW.found_target = 1.0;

      // '<S1>:1:26' target_pos = pos_xyz;
      guidance_sub_DW.target_pos[0] = guidance_sub_U.pos_xyz[0];
      guidance_sub_DW.target_pos[1] = guidance_sub_U.pos_xyz[1];
      guidance_sub_DW.target_pos[2] = guidance_sub_U.pos_xyz[2];

      // '<S1>:1:27' next_wps = target_pos;
      rtb_next_wps_idx_0 = guidance_sub_DW.target_pos[0];
      rtb_next_wps_idx_1 = guidance_sub_DW.target_pos[1];
      rtb_next_wps_idx_2 = guidance_sub_DW.target_pos[2];
    }
  } else {
    // '<S1>:1:29' else
    // '<S1>:1:30' next_wps = target_pos;
    rtb_next_wps_idx_0 = guidance_sub_DW.target_pos[0];
    rtb_next_wps_idx_1 = guidance_sub_DW.target_pos[1];
    rtb_next_wps_idx_2 = guidance_sub_DW.target_pos[2];
  }

  // End of MATLAB Function: '<Root>/guidance_function'

  // Outport: '<Root>/target_pos_xyz'
  guidance_sub_Y.target_pos_xyz[0] = rtb_next_wps_idx_0;
  guidance_sub_Y.target_pos_xyz[1] = rtb_next_wps_idx_1;
  guidance_sub_Y.target_pos_xyz[2] = rtb_next_wps_idx_2;
}

// Model initialize function
void guidance_subModelClass::initialize()
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(getRTM(), (NULL));

  // states (dwork)
  (void) memset((void *)&guidance_sub_DW, 0,
                sizeof(DW_guidance_sub_T));

  // external inputs
  (void)memset((void *)&guidance_sub_U, 0, sizeof(ExtU_guidance_sub_T));

  // external outputs
  (void) memset(&guidance_sub_Y.target_pos_xyz[0], 0,
                3U*sizeof(real_T));

  // SystemInitialize for MATLAB Function: '<Root>/guidance_function'
  // '<S1>:1:5' j = 1;
  guidance_sub_DW.j = 1.0;

  // '<S1>:1:6' target_pos = [0 0 0]';
  guidance_sub_DW.target_pos[0] = 0.0;
  guidance_sub_DW.target_pos[1] = 0.0;
  guidance_sub_DW.target_pos[2] = 0.0;

  // '<S1>:1:7' found_target = 0;
  guidance_sub_DW.found_target = 0.0;
}

// Model terminate function
void guidance_subModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
guidance_subModelClass::guidance_subModelClass()
{
}

// Destructor
guidance_subModelClass::~guidance_subModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_guidance_sub_T * guidance_subModelClass::getRTM()
{
  return (&guidance_sub_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
