#include <stdio.h>
#include <stdlib.h>

class ClassA
{
public:
    void sun()         { printf("\tClassA sun\n"); }
    virtual void mon() { printf("\tClassA mon\n"); }
    virtual void tue() { printf("\tClassA tue\n"); }
    virtual void wed() { printf("\tClassA wed\n"); }
private:
    char data[256];
};

class ClassB : public ClassA
{
public:
    void sun()          { printf("\tClassB sun\n"); }
    virtual void mon()  { printf("\tClassB mon\n"); }
    virtual void tue()  { printf("\tClassB tue\n"); }
private:
    char dataB[256];
};

class ClassC : public ClassA
{
public:
    virtual void mon()  { printf("\tClassC mon (%#lx)\n", this); }
    virtual void thu()  { printf("\tClassC thu (%#lx)\n", this); }
private:
    char dataC[256];
};

class ClassD : public ClassB, public ClassC
{
public:
    virtual void fri()  { printf("\tClassD fri (%#lx)\n", this); }
};

int main(int argc, void **argv)
{
    void(**vTable)(ssize_t);
    void(**vTable2)(ssize_t);

    printf("D:\n");
    ClassD * d = new ClassD;
    printf("size: %d bytes\n", sizeof(ClassD));
    vTable = *(void(***)(ssize_t))d;
    char * v = ((char *)d) + 256 + 256 + sizeof(ssize_t);
    vTable2 = *((void(***)(ssize_t))v);
    printf("  vTable[0]: %#lx", vTable[0]); vTable[0](0x1000);
    printf("  vTable[1]: %#lx", vTable[1]); vTable[1](0x1000);
    printf("  vTable[2]: %#lx", vTable[2]); vTable[2](0x1000);
    printf("  vTable[3]: %#lx", vTable[3]); vTable[3](0x1000);
    printf("\n");
    printf("  vTable2 = %#lx\n", vTable2);
    printf("  vTable2[0]: %#lx", vTable2[0]); vTable2[0](0x1000);
    printf("  vTable2[1]: %#lx", vTable2[1]); vTable2[1](0x1000);
    printf("  vTable2[2]: %#lx", vTable2[2]); vTable2[2](0x1000);
    printf("  vTable2[3]: %#lx", vTable2[3]); vTable2[3](0x1000);
    

    return 0;
};

