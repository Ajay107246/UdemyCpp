#pragma once
#ifndef CALLBACKSFUNCTIONPTR__H
#define CALLBACKSFUNCTIONPTR__H

/*
    function sorts an array, and with template which accepts array by reference.
    this is simple sorting algorithm that performs comparision of elements

    this function sort only in ascending order, and what if we need descending, or raw c-style string
    comparision operator won't work on strings, cause it'll compare address.

*/
template<typename T, int size>
void sort(T(&arr)[size]);

void all_callbacksFunctionPtr_methods();

#endif //CALLBACKSFUNCTIONPTR__H
#pragma endregion


