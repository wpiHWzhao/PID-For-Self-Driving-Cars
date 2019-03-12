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
  double controlLaw(double cte);

 private:
  /**
   * PID Errors
   */
  double iError=0;
  double dErrorInit=0;

  /**
   * PID Coefficients
   */ 
  double _Kp;
  double _Ki;
  double _Kd;

  // Initialization flag
  bool initialized = false;
};

#endif  // PID_H