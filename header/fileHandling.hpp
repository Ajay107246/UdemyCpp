#pragma once
#ifndef FILEHANDLING_H
#define FILEHANDLING_H
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

using namespace std::experimental::filesystem;
using namespace std;

void writeFile();
void readFile();

//Topic63-2
int copyUtility();

//Topic63-6
void usingFstream();

/* Topic63-7: Binary-IO operation from file handlder*/
//void usingBinMode();
#pragma endregion
#endif