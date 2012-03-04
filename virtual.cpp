#include <stdio.h>
#include <stdlib.h>

class ClassA
{
public:
    void sun()         { printf("\tClassA sun\n"); }
    virtual void mon() { printf("\tClassA mon\n"); }
    virtual void tue() { printf("\tClassA tue\n"); }
    virtual void wed() { printf("\tClassA wed\n"); }
};

class ClassB : public ClassA
{
public:
    virtual void mon() { printf("\tClassB mon (%#lx)\n", this); }
};

int main(int argc, void **argv)
{
    void(**vTable)(ssize_t);
    
    printf("A:\n");
    ClassA * a = new ClassA;
    vTable = *(void(***)(ssize_t))a;
    printf("  vTable[0]: %#lx", vTable[0]); vTable[0](0x1000);
    printf("  vTable[1]: %#lx", vTable[1]); vTable[1](0x1000);
    printf("  vTable[2]: %#lx", vTable[2]); vTable[2](0x1000);

    printf("B:\n");
    ClassB * b = new ClassB;
    vTable = *(void(***)(ssize_t))b;
    printf("  vTable[0]: %#lx", vTable[0]); vTable[0](0x1000);
    printf("  vTable[1]: %#lx", vTable[1]); vTable[1](0x1000);
    printf("  vTable[2]: %#lx", vTable[2]); vTable[2](0x1000);

    return 0;
};

