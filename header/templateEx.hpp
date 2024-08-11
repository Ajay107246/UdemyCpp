#pragma once
#ifndef TEMPLATEEX__H
#define TEMPLATEEX__H
#include <iostream>

int MAX(int x, int y);

float MAX(float x,float y);

void allTemplateMethods();

template <typename T>
T MAX(T x, T y);


#pragma endregion
#endif