#pragma once
/*
 * Programmieren fuer Physiker, SS 2023, Blatt 03, Aufg. 7
 *
 * kubische Gleichung loesen. Fragment.
 */

#include <iostream>
#include <cmath>
using namespace std;

// reelle dritte Wurzel berechnen, auch fuer neg. Argumente
double cubicroot(double x)
{
    if (x > 0) return exp(log(x) / 3.0);
    if (x < 0) return -exp(log(-x) / 3.0);
    return 0.0;
}

