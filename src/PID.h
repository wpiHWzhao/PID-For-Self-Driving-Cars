#ifndef PID_H
#define PID_H

#include <iostream>

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void InitPara(double Kp_, double Ki_, double Kd_, double dErrorIn);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  double UpdateError(double cte);


  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

  double iError=0;
  double dErrorInit=0;
  double totalError=0;

 private:
  /**
   * PID Errors
   */
  double _p_error;
  double _i_error;
  double _d_error;

  /**
   * PID Coefficients
   */ 
  double _Kp;
  double _Ki;
  double _Kd;

  int count=0;
  bool initialized = false;
};

#endif  // PID_H