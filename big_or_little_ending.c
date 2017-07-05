#include <stdio.h>
#include <stdlib.h>

void test()
{
    /// test the system is little ending or big ending
    union
    {
        short value;
        char bytes[sizeof(short)];
    }test;
    test.value = 0x0102;

    if ((test.bytes[0] == 1) && (test.bytes[1] == 2))
        printf("Big ending\n");
    else if ((test.bytes[0] == 2) && (test.bytes[1] == 1))
        printf("Little ending\n");
    else
        printf("unknown...\n");
}


int main()
{
    test();
    return 0;
}
