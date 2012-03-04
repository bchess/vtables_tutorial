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

class ClassB
{
public:
    void sun()          { printf("\tClassB sun\n"); }
    virtual void mon()  { printf("\tClassB mon\n"); }
    virtual void thu()  { printf("\tClassB thu\n"); }
};

class ClassC : public ClassA, public ClassB
{
};

class ClassD : public ClassC
{
};

int main(int argc, void **argv)
{
    void(**vTable)(ssize_t);
    void(**vTable2)(ssize_t);

    printf("A:\n");
    ClassD * d = new ClassD;
    vTable = *(void(***)(ssize_t))d;
    vTable2 = ((void(***)(ssize_t))d)[1];
    printf("  vTable[0]: %#lx", vTable[0]); vTable[0](0x1000);
    printf("  vTable[1]: %#lx", vTable[1]); vTable[1](0x1000);
    printf("  vTable[2]: %#lx", vTable[2]); vTable[2](0x1000);
    printf("  vTable[3]: %#lx\n", vTable[3]); // vTable[3](0x1000);
    printf("\n");
    printf("  vTable2[0]: %#lx", vTable2[0]); vTable2[0](0x1000);
    printf("  vTable2[1]: %#lx", vTable2[1]); vTable2[1](0x1000);
    printf("  vTable2[2]: %#lx\n", vTable2[2]); // vTable2[2](0x1000);

    return 0;
};

