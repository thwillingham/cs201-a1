#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"

int main()
{
    
    heap *h = newHeap();
    int i;
    //list *q = newLList();

    for (i=0; i<12; i++)
    {
        printf("\nmain: %d\n",i);
        insertItem(h,i);
        //node *n = newNode();
        //setNodeValue(n,i);
        //enqueue(q,n);
        
    }
    for (i=0; i<12; i++)
    {
        //printf("%d\n",getNodeValue(dequeue(q)));    
    }


    printHeap(h);

    
    return 0;
}
