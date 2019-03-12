#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::InitPara(double Kp, double Ki, double Kd, double dErrorIn) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   if (!initialized){
       _Kp = Kp;
       _Ki = Ki;
       _Kd = Kd;
       dErrorInit = dErrorIn;
       initialized= true;
       std::cout<<"PID initialized!"<<std::endl;
   }
}

double PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
   double dError = cte-dErrorInit;
   iError += cte;
   dErrorInit = cte; // store previous frame d error
   double pError = cte;
   double dSteer = _Kp*pError+_Ki*iError+_Kd*dError;
   count++;
   totalError+=cte*cte;
   return dSteer;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return totalError/count;  // TODO: Add your total error calc here!
}
