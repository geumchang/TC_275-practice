
/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Total_Pjt.c
 *
 * Code generated for Simulink model 'Total_Pjt'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Jan 22 12:56:26 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Total_Pjt.h"
#include <math.h>
#include "rtwtypes.h"

/* Block states (default storage) */
DW_Total_Pjt_T Total_Pjt_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Total_Pjt_T Total_Pjt_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Total_Pjt_T Total_Pjt_Y;

/* Real-time model */
static RT_MODEL_Total_Pjt_T Total_Pjt_M_;
RT_MODEL_Total_Pjt_T *const Total_Pjt_M = &Total_Pjt_M_;

/* Model step function */
void Total_Pjt_step(void)
{
  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/pushSwitch'
   */
  if (!Total_Pjt_U.pushSwitch) {
    /* Outputs for IfAction SubSystem: '<Root>/sw_on' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Outport: '<Root>/blueLed' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion'
     *  Sin: '<Root>/Sine Wave'
     */
    Total_Pjt_Y.blueLed = (uint16_T)floor(sin((real_T)Total_Pjt_DW.counter * 2.0
      * 3.1415926535897931 / 300.0) * 25000.0 + 25000.0);

    /* End of Outputs for SubSystem: '<Root>/sw_on' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/sw_off' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Outport: '<Root>/blueLed' incorporates:
     *  Constant: '<Root>/Constant'
     *  SignalConversion generated from: '<S1>/In1'
     */
    Total_Pjt_Y.blueLed = 0U;

    /* End of Outputs for SubSystem: '<Root>/sw_off' */
  }

  /* End of If: '<Root>/If' */

  /* Update for Sin: '<Root>/Sine Wave' */
  Total_Pjt_DW.counter++;
  if (Total_Pjt_DW.counter == 300) {
    Total_Pjt_DW.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */
}

/* Model initialize function */
void Total_Pjt_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Total_Pjt_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
has popup
