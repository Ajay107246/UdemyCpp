#pragma once
#ifndef CALLBACKSFUNCTIONPTR__H
#define CALLBACKSFUNCTIONPTR__H

/*
    function sorts an array, and with template which accepts array by reference.
    this is simple sorting algorithm that performs comparision of elements

    this function sort only in ascending order, and what if we need descending, or raw c-style string
    comparison operator won't work on strings, cause it'll compare address.

    need to work on > operator to generalize expression and perform comparison on any data type (>/<)
    implement using function pointer by modifying signature of sort() to accept one more param that ptr to function
    that function implemented by usr of sort() algorithm
    they will decide how to compare the elements
    added prototype comparator here in header


*/
using comparator = bool(*)(int, int);

bool CompAsc(int x, int y);
bool CompDisc(int x, int y);

template<typename T, int size>
void sort(T(&arr)[size]);

void all_callbacksFunctionPtr_methods();

#endif //CALLBACKSFUNCTIONPTR__H
#pragma endregion


