#pragma region override
#include <iostream>

using namespace std;
//Topic59, -1 
class DocumentAbst
{
    public:
    // virtual void serializeAbst(float version); // (59) no override restriction to derived class
    /*
    1. this pure virtual function won't have any implementation 
    2. but child class have to provide it. (59-1) override restriction to derived class
    3. class become abstract class and it should / has at least one pure virtual function
    4. this class cannot be instantiated 
    5. but can create there ptr and reference, can points to its child class objects.
    6. any client invoked serializeAbst() on DocumentAbst{} ptr/ref, guranteed that impl. is present in child classes
    7. forced derived class, to overried serializeAbst()
    8. side note: can have non-vitual function, data member, static mem-fucntion, etc.
    9. (3),(4)
    10. Abstract class used for creating interfaces
    
    11. pure virtual function can have its own implementation (optional)
    12. cannot be invoked (only with derived class)
    13. no entry in Vtable, but still defined layout of function in VTable of child classes
    
    */
    virtual void serializeAbst(float version) = 0 ;    
};

class TextAbst : public DocumentAbst
{
    void serializeAbst(float version)override final;
};

class RichTextAbst : public TextAbst
{
    /*
    1. TextAbst::serializeAbst(float version) can not be override here.
    2. since it FINAL in TextAbst class
    void serializeAbst(float version)override;
    */
};

class XMLAbst : public DocumentAbst
{
    public:
    /*
    1. Don't override serializeAbst()
    2. but serializeAbst() ofDocumentAbst gets inherited in XMLAbst{} class
    3. if the client invkode serializeAbst() on DocumentAbst *dc -> pointing to XMLAbst
    4. serializeAbst() from DocumentAbst{} will get invoked
    5. default impl. of serializeAbst() get invoked
    6. this function won't know how serialized the data of XMLAbst{}
    7. then XMLAbst data won't get serialized but client code won't know that
    8. all is know about -> serializeAbst() get invoked DocumentAbst *dc, not from XMlAbst{}
    9. create a instance of XMLAbst in main() and invoke writeDoc()
    10. derived class of DocumentAbst{} aren't force to override the serializeAbst()
    11. to make this restriction of override, need to make serializeAbst() in base class -> pure virtual function
    12. this pure virtual function won't have any implementation but child class have to provide it.
    13 base class become abstrct class -> have to provide override functions in derived class from it.
    */
    void serializeAbst(float version)override;
};

#pragma endregion

void writeDoc(DocumentAbst *dc);