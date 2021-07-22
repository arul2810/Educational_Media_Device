/*
 * PrivateTimer.c- Stop Watch
 *
 *  Created on: Mar 24, 2021
 *      Author: Arul Prakash Samathuvamani | el20a2ps@leeds.ac.uk
 */


#ifndef PRIVATETIMER_H_
#define PRIVATETIMER_H_

// function to initialise the timer
void intialise_timer( signed int timer_load_value );

// Check if the timer has reached counting down to zero, if yes interrrupt becomes high.
unsigned int interrupt_status ( void ) ;

// reset the timer interrupt. Timer starts to count again.
void reset_interrupt ( void );

#endif /* PRIVATETIMER_H_ */
