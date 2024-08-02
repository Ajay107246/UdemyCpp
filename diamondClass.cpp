#include "diamondClass.h"
#include <iostream>
#include <string>

using namespace std;

Stream::Stream(const string &filename): m_fileName(filename)
{
    cout << "Stream::Stream(const string &filename)" << endl;
}

const string &Stream::getFilename() const
{
    // TODO: insert return statement here
    return m_fileName;
}

Stream::~Stream()
{
    cout << "Stream::~Stream()" << endl;
}

oStream::oStream(ostream &o, const string &filename):out(o), Stream(filename)
{
    cout << "oStream::oStream(ostream &o, const string &filename):out(o), Stream(filename)" << endl;

}

ostream &oStream::operator<<(const string &data)
{
    // TODO: insert return statement here
    out << data;
    return out;
}

oStream::~oStream()
{
    cout << "oStream::~oStream()" << endl;
}

iStream::iStream(istream &i, const string &filename):in(i), Stream(filename)
{
    cout << "iStream::iStream(istream &i, string &filename):in(i), Stream(filename)" << endl;
}

istream & iStream::operator >> (string &data)
{
    // TODO: insert return statement here
    in >> data;
    return in;
}

iStream::~iStream()
{
    cout << "iStream::~iStream()" << endl;
}

ioStream::ioStream(const string &filename):oStream(cout, filename), iStream(cin, filename), Stream(filename)
{
    cout << "ioStream::ioStream(const string &filename):oStream(cout, filename), iStream(cin, filename)" << endl;
}

ioStream::~ioStream()
{
    cout << "ioStream::~ioStream()" << endl;
}
