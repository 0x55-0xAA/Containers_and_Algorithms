#include <stdio.h>

int add(int a,int b) {
    int res;
    __asm__(
        "movl %1,%%eax;"
        "addl %2,%%eax;"
        "movl %%eax,%0;"
        :"=r"(res)
        :"r"(a),"r"(b)
        :"%eax"
    );
    return res;
}
int main(int argc, char const *argv[])
{
    int a = 1,b = 1;
    printf("%d\n",add(a,b));
    return 0;
}
