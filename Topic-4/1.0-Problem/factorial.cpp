//
// Created by Marc Verges on 19/10/23.
//
#pragma once

#include <iostream>
using namespace std;

int factorial(int n)
{
    int fac;

    if (n == 0)
    {
        fac = 1;
    }
    else
    {
        fac = n* factorial(n-1);
    }
    return fac;
}