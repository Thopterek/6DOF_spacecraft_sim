#include "cannon.h"

/*
  * ---[Introduction to the problem]---
  * Determining the trajectory and time of impact of a cannon ball
  * it is fired with an initial speed and angle, assuming constant gravity
  *
  * ---[Description of writing structure]---
  * the sign -> should be above the variable that is prior to it
  * eg. a->(t), in this case -> relates to a
  * if its about matrix [<first_goes_up> <second_goes_low>]
  * when needed adding [0<up> -9.81<low>]
  *
  * ---[Modeling the Cannonball]---
  * cannon ball acceleration is constant:
  *         a->(t) = g->
  * 
  * on earth, at sea-level, g will be approx -9,81 meter per second squared:
  *         g->=[0 -9.81]
  * 
  * acceleration is the derivative of velocity with with respect to time:
  *         velocity->(t) = gt-> + velocity->subscript_0
  *
  * where the initial velocity is:
  *         velocity subscript 0-> = [speed * cos theta<up> speed * sin theta<low>]
  *
  * the position of the cannon ball [p(t)] is found by anti-differentiating v(t)
  *         p->(t) = 1/2gt->power_2 + velocity->subscript_0 + p->subscript_0
  *
  * impact is when the cannon ball hits the ground, y coordinate reaches 0
  *         y(t subscript_impact) = 1/2gt power_2 + velocity subscript_y0 t + y0 = 0
  *
  * solving for t with quadratic formula we get the time of impact:
  *         t subscript_impact = (-velocity subscript_y0 - root(velocity power_2 subscript_y0 - 2y0))/g
  *
  * ---[Compilation]---
  * cc cannon_no_trick.c -o simulate_cannon -lm
*/

// ---[Implementation without fns]---
int main(void) {
  double pos[2], pos_orig[2];
  double vel[2], vel_orig[2];
  double acc[2];
  double init_angle, init_speed, time, impactTime;
  int impact;
  pos[0] = 0.0; pos[1] = 0.0;
  vel[0] = 0.0; vel[1] = 0.0;
  acc[0] = 0.0; acc[1] = -9.81;
  time = 0.0;
  init_angle = M_PI/6.0;
  init_speed = 50.0;
  impact = 0;
  pos_orig[0] = pos[0]; pos_orig[1] = pos[1];
  vel_orig[0] = cos(init_angle) * init_speed;
  vel_orig[1] = sin(init_angle) * init_speed;
  printf("time, pos[0], pos[1], vel[0], vel[1]\n");
  while (!impact) {
    vel[0] = vel_orig[0] + acc[0] * time;
    vel[1] = vel_orig[1] + acc[1] * time;
    pos[0] = pos_orig[0] + (vel_orig[0] + 0.5 * acc[0] * time) * time;
    pos[1] = pos_orig[1] + (vel_orig[1] + 0.5 * acc[1] * time) * time;
    printf("%7.2f, %10.6f, %10.6f, %10.6f, %10.6f\n", time, pos[0], pos[1], vel[0], vel[1]);
    if (pos[1] < 0.0) {
      impact = 1;
      impactTime = (- vel_orig[1] - sqrt(vel_orig[1] * vel_orig[1] - 2.0 * pos_orig[1])) / -9.81;
      pos[0] = impactTime * vel_orig[0];
      pos[1] = 0.0;
    }
    time += 0.01;
  }
  printf("Impact time = %lf position = %lf\n", impactTime, pos[0]);
  return (0);
}

