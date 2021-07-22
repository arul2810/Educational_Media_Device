/*
 * SevenSeg.h
 *
 *	7-Segment Display Driver
 *
 *  Created on: Mar 23, 2021
 *      Author: Arul Prakash Samathuvamani | Based on Driver design in Unit 1 Examples.
 */

#ifndef SEVENSEG_H_
#define SEVENSEG_H_


void sevenseg_write (unsigned int display , unsigned char value);

void sevenseg_single(unsigned int display, unsigned int value);

void sevenseg_double(unsigned int display, unsigned int value);

#endif /* SEVENSEG_H_ */
