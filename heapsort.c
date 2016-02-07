#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "node.h"
#include "linkedList.h"

int main()
{
    heap *h = newHeap();
    int numbers[] = {4645,463,46,762,25,6,234,1,7,8,356,83,234,123};    
    int i;
    for (i=0; i<12; i++)
    {
        insertItem(h,numbers[i]);
    }

    printHeap(h);

    return 0;
}
