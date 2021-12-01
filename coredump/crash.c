#include <stdio.h>
#include <unistd.h>

int *null_ptr = NULL;

int call_prt(int value)
{
    *null_ptr = value;   
    return 0;
}

int main()
{
    int value =100;
    call_prt(value);
    return 0;
}
