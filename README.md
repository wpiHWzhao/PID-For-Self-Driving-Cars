# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Description

In this project, a PID controller is implemented to control a self-driving car on a simulated track.

### Parameter Tuning 

I follow the tuning procedure on Wiki:

![pid](PID.gif)

* First increase Kp to let the car have a steady oscillation around the desired trajectory.
* Increase Kd until the oscillation goes away.
* Slightly increase the Ki to bring the system to desired trajectory(with cte around 0). This would introduce some overshot but give the system a quicker response.

I tuned the controller manually. Initially I first use [0.1,0,0] (Kp,Ki,Kd) and slightly increase Kp to 0.13 to have a steady oscilation, then I increased the Kd term to 2.6 to stop the oscilation. I tried to increase Ki to have a quicker response but it introduce more oscilation. Therefore I set it to 0.

### Effect of P, I, D 

* The proportional gain Kp would steer the car towards the center line. But this would always overshoot.
* The integral portion would eliminate a possible bias on the controlled system. Normally it would lead to a quicker response but alse introduce a little bit oscillations. 
* The differential portion helps to smooth the oscillation introduced by the Kp. But if it is too large the car would start to chatter. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.
