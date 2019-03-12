#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::InitPara(double Kp, double Ki, double Kd, double dErrorIn) {
   if (!initialized){
       _Kp = Kp;
       _Ki = Ki;
       _Kd = Kd;
       dErrorInit = dErrorIn;
       initialized= true;
       std::cout<<"PID initialized!"<<std::endl;
   }
}

double PID::controlLaw(double cte) {
   double dError = cte-dErrorInit;
   iError += cte;
   dErrorInit = cte; // store previous frame d error
   double pError = cte;
   double dSteer = _Kp*pError+_Ki*iError+_Kd*dError; // PID controller
   return dSteer;
}
