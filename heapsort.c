#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"

int main()
{
    
    heap *h = newHeap();
    h->type = 1;
   
    importFile(h,"./integers");

    heapify(h);
    printHeap(h);

    
    return 0;
}
