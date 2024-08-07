#pragma once
#ifndef BINFILEHANDLING_H
#define BINFILEHANDLING_H
#include <experimental/filesystem>
#include <iostream>

/* Topic63-7: Binary-IO operation from file handlder*/
void usingBinMode();

struct Record{
    int id;
    char name[10];

};
void writeBinRecords(Record *p);

Record getBinRecords();


/*
Assignemnt1:
Modify the file copy utility to support copying of binary files. Here are some guidelines:

Use read & write functions of the stream classes instead of getline, operator << or >>.
Remember, binary files don't have EOF marker, so you'll have to read the file based on its size.
Take help of the filesystem library to manage paths. (path class, current_path(), is_directory(), etc)
Handle stream errors appropriately
Prevent existing files from being overwritten during copy operations. Show a suitable message if a file will be overwritten.
Here is the link to the documentation of filesystem library: http://en.cppreference.com/w/cpp/header/experimental/filesystem

Assignemnt1:
Modify the file copy utility to support following:

Accept file names through command line
If the source is a directory, then copy the content of the entire directory. e.g. C:\copyutil c:\myfiles d:\oldfiles. All files in copyutil will be copied to myfiles directory. If the target directory does not exist, then create it.
Show the progress of copy for each file as shown in the image below.


*/

#pragma endregion
#endif