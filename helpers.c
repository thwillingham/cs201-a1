#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"
#include "node.h"
#include "heap.h"

int compare(int type, node *a, node *b)
{

    if (!type) //min heap
    {
        return a->value>b->value;
    } else if (type) //max heap
    {
        return a->value<b->value;
    }

}

void importFile(heap *h, char* fName)
{
    FILE* file = fopen(fName,"r");
    int i=0;
    fscanf(file, "%d", &i);
    while (!feof(file))
    {
        insertItem(h, i);
        fscanf(file, "%d", &i);
    }
    fclose(file);
}
