/* Topic60: Multiple Inheritance (Diamond problem) */
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stream
{
    string m_fileName;
    public:
    Stream(const string &filename); //parameterized constr
    const string & getFilename()const; /* also get invoked twice, if no virtual at inheritance class*/
    ~Stream();

};

/*
virtual inheritance
compiler add vptr to object of Stream within oStream object
*/
class oStream : virtual public Stream   /*if we put virtual, constr of Stream{} needs to be invoke */
{
    ostream &out;   //to write to file (just printing on screen)
    public:
    //init above reference through constr with specifying the m_fileName
    oStream(ostream &o, const string &filename); //:out(o), Stream(filename);
    //override insertion operators
    ostream & operator<<(const string & data);
    ~oStream();
};

/*
virtual inheritance
compiler add vptr to object of Stream within iStream object
*/
class iStream : virtual public Stream
{
    istream &in;    //to read from from()
    public:
    iStream(istream &i, const string &filename); //:in(i), Stream(filename);
    //override extraction operators
    istream & operator >> (string & data);
    ~iStream();
};

/*
instance of ioStream contains instance of oStream & iStream
within these -> 2x vptr of oStream & iStream objects
points to single instance of Stream{}
entire ioStream{} contains only one instance of Stream() object
-> make sure to invoke constr of Stream() from ioStream() constr
to call any methods from Stream{}

NOTE: here after returning to ioStrea{}, 
compiler go back to oStream() constr which will not invoke constr of Stream() sine its virtual base class{}
and then after going back to ioStream, iStream() constr will be invoked
then iostream object fully initialized.

*/
class ioStream : public oStream, public iStream
{
    public:
    //constr - init ots base class objects
    ioStream(const string &filename);//: oStream(cout, filename), iStream(cin, filename); //not in this way -> error error: expected '{' at end of input
    ~ioStream();
};

/*
create instance of ioStream("out.txt") in main()
output:
Stream() invoked twice
*/