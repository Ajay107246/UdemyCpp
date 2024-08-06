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
    
    /*Topic63-3*/
    string message("Topic63-3: This is another example of File operations-char IO & seeking");
    ofstream outChar;
    outChar.open("testFileOps.txt");
    if (!outChar)
    {
        cout << "Topic63-3, could not open file for writing!" << endl;
        return;
    }    
    for(char ch: message)
    {
        outChar.put(ch);
    }
    outChar.seekp(0,ios::end);
    outChar.put('#');
    //Topic63-5, output: Topic63-3: This is another example of File operations-char IO & seeking#
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
    ifstream inChar;
    inChar.open("testFileOps.txt");
    if (!inChar)
    {
        cout << "Topic63-3, testFileOps.txt not found for reading!" << endl;
        return;
    }
    cout << "Topic63-4, before seekg() current position is: " << inChar.tellg() << endl;
    /* to change the position of get-ptr use seekg()
    //seekg() has 2 overload values, offest/position, base position [can have 3 values]
    1. ios::be() -> beginning 
    2. ios::cur() -> current position
    3. ios::end() -> start from end
    */

    //inChar.seekg(5); //output: 63-3: This is another example of File operations-char IO & seeking   
    /*
    output1:
    Topic63-4, before seekg() current position is: 0
    Topic63-4, after seekg() current position is: 5
    63-3: This is another example of File operations-char IO & seeking
    */    
    //inChar.seekg(-5, ios::end); // reading file again from last 5th pos from end of file
    //cout << "Topic63-4, after seekg(-5, ios::end) position is: " << inChar.tellg() << endl;
    /*
    output2:
    Topic63-4, after seekg(-5, ios::end) position is: 66
    eking
    */
    inChar.seekg(10, ios::beg); // reading file again from 10th pos from begin
    cout << "Topic63-4, after seekg(10, ios::beg) position is: " << inChar.tellg() << endl;
    
    /*
    output3:
    Topic63-4, after seekg(10, ios::beg) position is: 10
    This is another example of File operations-char IO & seeking
    */
    
    char ch{};
    while (inChar.get(ch))
    {
        cout << ch; // this will print from location (5)/(-5, end) as per seekg(5)/seek(-5, end)
    }
    cout << endl; 
    inChar.close();   
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

