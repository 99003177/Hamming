/** 
* @file hamming1.h
*
*/
#ifndef __HAMMING1_H__
#define __HAMMING1_H__

/**
* Finds error during transmission of data
* @param[m_size] number of bits in the message
* @param[msg] data message
* @returns corrected data message along with parity bits
*/
int * hamming1(int msg[],int m_size,int data1[]);


#endif