#include "abstractClass.h"

using namespace std;

void DocumentAbst::serializeAbst(float version)
{
    cout << "virtual DocumentAbst::serializeAbst(float version)" << endl;
}

void TextAbst::serializeAbst(float version)
{
    cout << " TextAbst::serializeAbst(float version)override final" << endl;
}
/*
//can not be override here since it FINAL in TextAbst class
void RichTextAbst::serializeAbst(float version)
{
    cout << " RichTextAbst::serializeAbst(float version)override" << endl;
}
*/

void writeDoc(DocumentAbst *dc)
{
    dc->serializeAbst(1.1f);
}

void XMLAbst::serializeAbst(float version)
{
    cout << "XMLAbst::serializeAbst(float version)override" << endl;
}
