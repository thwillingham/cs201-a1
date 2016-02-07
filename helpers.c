#include <stdio.h>
#include <stdlib.h>

int compare(char* type, int a, int b)
{

    if (type == 'min') //min heap
    {
        return a<b;
    } else if (type == 'max') //max heap
    {
        return a>b;
    }

}


