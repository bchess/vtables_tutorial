#include <stdio.h>
#include <stdlib.h>

class ClassA
{
public:
    void sun()         { printf("ClassA sun\n"); }
    virtual void mon() { printf("ClassA mon\n"); }
    virtual void tue() { printf("ClassA tue\n"); }
    virtual void wed() { printf("ClassA wed\n"); }

private:
    char aData[256];
};

class ClassB
{
public:
    void sun()          { printf("ClassB sun\n"); }
    virtual void mon()  { printf("ClassB mon\n"); }
    virtual void tue()  { printf("ClassB tue\n"); }
private:
    int bData;
};

class ClassC : public ClassA, public ClassB
{
public:
    virtual void mon()  { printf("ClassC mon (%#lx)\n", this); }
};

void MyFunctionA(ClassA *a)
{
    printf("a: %#lx\n", a);
}

void MyFunctionB(ClassB *b)
{
    printf("b: %#lx\n", b);
}

void MyFunctionC(ClassC *c)
{
    printf("c: %#lx\n", c);
}


int main(int argc, void **argv)
{
    ClassC * c = new ClassC;
    MyFunctionA(c);
    MyFunctionB(c);
    MyFunctionC(c);

    printf("\nUsing C-style cast (c->a and c->b)\n");
    ClassA * a = (ClassA *)c;
    ClassB * b = (ClassB *)c;
    MyFunctionA(a);
    MyFunctionB(b);
    MyFunctionC(c);

    printf("\nUsing C-style cast (c->a and a->b)\n");
    a = (ClassA *)c;
    b = (ClassB *)a;
    MyFunctionA(a);
    MyFunctionB(b);
    MyFunctionC(c);

    printf("\nUsing reinterpret-style cast (c->a and c->b)\n");
    a = reinterpret_cast<ClassA *>(c);
    b = reinterpret_cast<ClassB *>(c);
    MyFunctionA(a);
    MyFunctionB(b);
    MyFunctionC(c);

    printf("\nUsing reinterpret-style cast (c->a and a->b)\n");
    a = reinterpret_cast<ClassA *>(c);
    b = reinterpret_cast<ClassB *>(a);
    MyFunctionA(a);
    MyFunctionB(b);
    MyFunctionC(c);


    printf("\nUsing static-style cast\n");
    a = (ClassA *)c;
    //b = static_cast<ClassB *>(a);
    MyFunctionA(a);
    printf("b: invalid static_cast from type 'ClassA*' to type 'ClassB*'\n");
    //MyFunctionB(b);
    MyFunctionC(c);

    printf("\nUsing dynamic-style cast\n");
    b = dynamic_cast<ClassB *>(c);
    a = dynamic_cast<ClassA *>(b);
    MyFunctionA(a);
    MyFunctionB(b);
    MyFunctionC(c);


    return 0;
};

