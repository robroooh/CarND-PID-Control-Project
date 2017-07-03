# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---



[hyp]: ./images/hyperparameters_tuning.png

## The effect each of the P, I, D components.

### The P is for proportional Control
How large or small the wheel need to turn in order to get on the trajectory line by getting the cross track error`(CTE)` multiply by the propotional gain `steering angle = Kp*cte`. However, this can leads to overshooting, where the car gets over the line too much which cause oscillating.


### The D is the derivative(time) Control
How fast we are moving to the trajectory line which can be found be taking the derivative term of the cte which we can roughly get `steering angle = Kd*(cte(t)-cte(t-1))` where `Kd` is the derivative gain.

### PD Control
`steering angle = Kp*cte + Kd*(cte(t)-cte(t-1))`

Now we got PD control, simply exmplained as `Kp` determined how fast we should move close to the line and `Kd` control to prevent the car goes too quickly to the line. That is, if the `Kd` is too low, the car will oscilate as usual, if the `Kd` is too high, the car will just take toooo long to get to the line.

However, the problem can persist on conditions where the faulty occurs in the car like the steering is unbalanced or face an obstacle which alters the angel of the car. 

### The I is the Integral Control
To take whose conditions to mind, we can add an ingetral term which is the sum of all `cte` multiply by integral gain determines how far we are from the line in overall which make a car adapts to changes.

To sum up, we got

### PID Control
`steering angle = Kp*cte + Kd*(cte(t)-cte(t-1)) + Ki*sum(cte)`

 - `Kp` is how fast we should go to the line
 - `Kd` is how to preventing goes to the line too fast
 - `Ki` is how fast the car should react when changes occur

but why don't we call it PDI control anyway

## How the final hyperparameters were chosen.

At first, I randomly changed the hyperparameters by sense, and I realize it's harder than I thought, so I went to the forum to find some technique on the initialized value of these 3. I come acrossed [this thread](https://robotics.stackexchange.com/questions/167/what-are-good-strategies-for-tuning-pid-loops/174#174) (which is the same one as my mentor sent me). The strategies are the following 
![hyp-tuning][hyp]

I followed the instructions here and it works great! However, it is not perfect and oscillate a bit.
I also play with twiddling, but it still has bugs and i'm running out of time, so i guess my initial values are just-pass for the submission. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
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

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
