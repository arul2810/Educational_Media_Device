/*
 * PrivateTimer.c- Stop Watch
 *
 *  Created on: Mar 24, 2021
 *      Author: Arul Prakash Samathuvamani | el20a2ps@leeds.ac.uk
 */

#include "PrivateTimer.h"

// points the pointers to corresponding base addresses

// set timer pointer to interrupt timer base address
volatile unsigned int *timer_base_ptr          = (unsigned int *)0xFFFEC600;

// set private timer load pointer to timer load address
volatile unsigned int *private_timer_load      = (unsigned int *)0xFFFEC600;

// set private timer pointer to timer value address
volatile unsigned int *private_timer_value     = (unsigned int *)0xFFFEC604;

// set private timer control pointer to timer control base address
volatile unsigned int *private_timer_control   = (unsigned int *)0xFFFEC608;

// set private timer interrupt to private timer interrupt base address
volatile unsigned int *private_timer_interrupt = (unsigned int *)0xFFFEC60C;



// function to initialise the timer
void intialise_timer ( signed int timer_load_value ) {
	
	
	*private_timer_load = timer_load_value ; // set the timer load value to timer load address

	// set PRESCALAR value of timer to zero. E = 1, A =1, I =0. i.e enable the timer
	// dis
	*private_timer_control = ( 0 << 8 ) | (0 << 2) | (1 << 1) | (1 << 0);
	
	
}

// Check if the timer has reached counting down to zero, if yes interrrupt becomes high.
unsigned int interrupt_status ( ) {
	
	unsigned int interrupt_value = *private_timer_interrupt; // declaration used for testing

	// return the value of interrupt.
	return *private_timer_interrupt;
	
}


// reset the timer interrupt. Timer starts to count again.
void reset_interrupt ( ) {
	
	// reset the value of interrupt.
	*private_timer_interrupt = 0x1;
	
}
