#include <iostream>
#include<experimental/filesystem>
#include <fstream>
#include <string>
#include "../header/binFileHandling.hpp"

using namespace std;
using namespace experimental::filesystem;

/* Topic63-7: Binary-IO operation from file handler*/
void usingBinMode()
{
    ofstream textStream;
    textStream.open("data");
    textStream << 123456789;    //this will be in readable format

    ofstream binTextStream;
    binTextStream.open("binary", ios::binary | ios::out);   //open file in binary/out mode
    int num {123456789};    //this number will be in binary format/above same number
    /* write bin data to file   
     data written in byte by byte -> type cast in const char*
    */
    binTextStream.write((const char*)&num,sizeof(num));  
    num =0;
    binTextStream.close();
    //read bin file
    ifstream binIfStream;
    binIfStream.open("binary", ios::binary | ios::in);
    binIfStream.read((char*)&num, sizeof(num));
    cout<< "num from binary file: " << num << endl;
}

/* Topic63-8: Binary-IO records operation from file handler*/
void writeBinRecords(Record *p)
{
    ofstream binOfStream;
    binOfStream.open("record", ios::binary | ios::out);
    binOfStream.write((const char *)p, sizeof(Record));
}

Record getBinRecords()
{
    ifstream binIfStream;
    binIfStream.open("record", ios::binary | ios::out);
    Record ro;
    binIfStream.read((char *)&ro, sizeof(Record));
    return ro;
}
