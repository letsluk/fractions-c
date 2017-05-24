
#ifndef _INCLUDED_FRAC
#define _INCLUDED_FRAC
#include <stdio.h>
#include <stdlib.h>
typedef struct frac
{
    int divident;
    int divisor;
} frac;

/**
 * @brief creates a new struct
 * @param divident divisor
 * 
 **/
extern frac * newFrac(int divident, int divisor);

/**
 * @brief prints a Frac
 * 
 **/
extern void printFrac(frac * self);

/**
 * @brief Multiplies two Fracs
 * 
 **/
extern  frac * multiplyFrac(frac * factor_1, frac * factor_2);

/**
 * @brief Turns a frac into its reciprocal
 **/
extern frac * reciprocal(frac * original);

/**
 * Divides first given frac by second given frac
 **/
extern frac * divideFrac(frac * divid, frac * divis);

/**
 * @brief Makes two fracs compatible for addition or substraction
 **/
extern void unifyFrac(frac * toUnify, frac * toLook);

/**
 * @brief adds two fracs
 **/
extern frac * sumFrac(frac * summand_1 , frac * summand_2);

/**
 * @brief makes the numbers in the frac as small as possible without changing its value
 **/
extern frac * shorten(frac * toShorten);

/**
 * @brief Converts a Frac to string
 **/
extern char * toString(frac* self, char * result);

/**
 * @brief Substracts second frac from first frac
 **/
extern frac * subFrac(frac * minuent, frac * subtrahent);

extern int compareFrac(frac * first, frac * second);
#endif
