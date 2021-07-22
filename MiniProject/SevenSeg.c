/*
 * SevenSeg.c
 *
 *	7-Segment Display Driver
 *
 *  Created on: Mar 23, 2021
 *      Author: Arul Prakash Samathuvamani | Based on Driver in Unit 1 Examples
 
 Changelog:
 
 Driver Fetches the corresponding HEX value to be fed from a array to map it.
 */

#include "SevenSeg.h"

/* Driver Functionality
 *
 * 7-segment display displays the value denoted by 7-bit address.
 *
 * X X X X X X X -  The corresponding dash turns on and off based on the value of X. Please refer technical report for mapping of bits.
 *
 */



// set the lower base address for 7-segment display. Denotes display 0-4
volatile unsigned char *sevenseg_base_low_addr = (unsigned char *) 0xFF200020;


// set the higher base address for 7-segment display. Dentoes display 5 and 6
volatile unsigned char *sevenseg_base_high_addr = (unsigned char *) 0xFF200030;

#define number_of_low_display 4 // Define the number of displays addressed by lower base address.

#define number_of_high_display 2 // Define the number of displays addressed by higher base address.

unsigned int number_map[10] = { 63,6,91,79,102,109,125, 7,127, 103 };


// Write the corresponding value to 7-Segment memory address.
void sevenseg_write(unsigned int display, unsigned char value){

	if(display < number_of_low_display ) { // if the display number is in lower base

		sevenseg_base_low_addr[display] = value; // write the value to lower base address

	}else{

		display = display - number_of_low_display; // else find the corresponding display in higher base address
		sevenseg_base_high_addr[display] = value; // and write the value to higher base address
	}

}

// Sets the value for single display
void sevenseg_single(unsigned int display, unsigned int value){
	
	
	if(value < 10 ){ // for a single display, values can be from 0-9 for stop watch or the display is turned off
		
			sevenseg_write ( display, number_map[value] );
		
	}else{
		sevenseg_write(display, 0); // else turn off the display.
	}
	
	
	
}

// used to set value in two displays.

void sevenseg_double(unsigned int display, unsigned int value){
	
	
	// if the value is less than 10, then only one display is needed
	if(value <10){
		
		sevenseg_single  (display,value); // display the value in first display
		sevenseg_single  (display+1,0); // and display zero in the next
		
	}

	// if the value is greater than 10, then both the displays are needed
	else{
	
		sevenseg_single (display,(value % 10)); // display the lower digit in first display
		sevenseg_single (display+1,( value / 10 ) ); // display the higher digit in second display
		
	}
	
	
}



