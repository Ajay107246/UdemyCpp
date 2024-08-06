#include "../header/fileHandling.hpp"
#include <experimental/filesystem>
#include <string>
#include <iostream>

using namespace std;

//Topic63-1
void writeFile()
{
    ofstream outFile;
    outFile.open("fileOperation.txt");
    outFile << "Hello World!" << endl;
    outFile << 10 << endl;
    outFile.close();
}

//Topic63-1
void readFile()
{
    ifstream inFile;
    inFile.open("fileOperation.txt");
    if (inFile.is_open())
    {
        cout << "File is open!" << endl;
    }
    else if (!inFile.is_open())
    {
        cout << "Could not open the File!" << endl;
    }
    else if (inFile.fail())
    {
        cout << "Could not open the File!" << endl;
    }
    
    string msg;
    getline(inFile, msg);
    int value{};
    inFile >> value;
    /*
    //try to read more character present in file -> it failed
    inFile >> value;
    if (inFile.fail())
    {
        cout << "Could not read!" << endl;
    }
    output:
    File is open!
    Could not read!
    Some I/O operation failed!
    Hello World!:10
    */
    if (inFile.good())
    {
        cout << "I/O operation is successful!" << endl;
    }
    else
    {
        cout << "Some I/O operation failed!" << endl;
    }
    if (inFile.eof())
    {
        cout << "End of file occured!" << endl;
    }
    /*
    inFile.setstate(ios::failbit);
    inFile.clear();
    */
    inFile.close();
    cout << msg << ':' << value << endl;
}

//Topic63-2: copy utility
//using namespace experimental::filesystem;

int copyUtility()
{
    path source(current_path());
    cout << "source(current_path()): " << source << endl;
    source /= "oopsConcept.cpp";

    path dest(current_path());
    dest /= "oopsConcept.txt";
    cout << "dest(current_path()): " << dest << endl;
    ifstream inputF{source};
    if(!inputF)
    {
        cout << "Source file not found! " << endl;
        return -1;
    }
    ofstream outputF{dest};
    string lines;
    while(!getline(inputF, lines).eof())
    {
        outputF << lines << endl;
    }
    inputF.close();
    if (!outputF)
    {
        cout << "dest: oopsConcept.txt file not found! " << endl;
    }
    else
    {
        cout << "dest: oopsConcept.txt file found! " << endl;
    }
    
    outputF.close();
    return 0;
}

