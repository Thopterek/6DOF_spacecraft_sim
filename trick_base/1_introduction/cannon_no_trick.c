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
  * on earth, at sea-level, g will be approx -9,81 meter per second squared:
  *         g->=[0 -9.81]
  * acceleration is the derivative of velocity with with respect to time,
  * is found by simply anti-differentiating a(t):
  *         velocity 0-> = [speed * cos theta<up> speed * sin theta<low>]
*/
int main(int ac, char **av) {
  // to be filled out
  (void)ac;
  (void)av;
  return (0);
}
