/*

Random Lib


*/
#pragma once
#include <iostream>
//#include
//#include <string>

//Random whole Nums
inline long rand_range(long min, long max)
{
    return rand()/(RAND_MAX / (max-min+1) + 1) + min;
}

//Random Decimal Numbers
inline double rand_01(void)
{
    //This gives a warning

    /*
    warning: conversion
    from ‘long int’ to ‘double’ may
    change value [-Wconversion]
    21 | return rand_range(0L,
    RAND_MAX-1L)/(RAND_MAX-1.0);

    Don't know how to fix it
    */

    return static_cast<double>(rand_range(0L, RAND_MAX-1L))
           /(static_cast<double>(RAND_MAX)-1.0);
}

inline double rand_range(double min, double max)
{
    return rand_01() * (max-min) + min;
}

//Random Char Values
inline char rand_range(char min, char max)
{
    return static_cast<char>(rand_range(static_cast<long>(min),
                                        static_cast<long>(max)));
}

//Random Action Occurence
// probability is expected to be a standard [0, 1] value
inline bool event_occurred(double probability)
{
    return rand_01() <= probability;
}

inline bool flip_coin(double chance_heads = 0.5)  // fair coin
{
    return event_occurred(chance_heads);
}
