#include "FinalOverride.h"
#include <iostream>
using namespace std;

Zip::Zip()
{
}

void Zip::compress()
{
}

void Zip::deCompress()
{
}

void Zip::printStatistics()
{
}

Zip::~Zip()
{
}

void Document::serialize(float version)
{
    cout << "Document::serialize(float version)!" << endl;
}

void Text::serialize(float version)
{
    cout << "Text::serialize(float version)!" << endl;
}

void FastText::serialize(float version)
{
    cout << "FastText::serialize(float version)!" << endl;
}
