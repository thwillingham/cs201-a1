#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"

int main(int argc, char **argv)
{
    

    char* info = "\n" 
        "##########################################################\n"
        "# Author: Thomas Willingham | twillingham@crimson.ua.edu\n"
        "# Course: CS201 | Dr. John C. Lusth\n"
        "# Assignment: 1\n"
        "# Purpose: This program is a pointer-based implementation\n"
        "#          of the Heapsort algorithm, that will read int-\n"
        "#          egers from a free-format file, sort them in\n"
        "#          ascending or descending order, and write them\n"
        "#          to the screen.\n"
        "##########################################################\n"
        "## Explanation of running time:\n"
        "##    step                          time\n"
        "##    -----------------------------------------\n"
        "##    constructing unordered heap | n\n"
        "##    transforming into heap      | nlogn\n"
        "##    popping from heap           | logn\n"
        "##    other operations            | O(1)\n"
        "##    -----------------------------------------\n"
        "##                           Total: theta(nlogn)\n"
        "##########################################################\n";
    int i = 0;
    int v = 0;
    int d = 0;
    char* file;
    int f = 0;
    if (argc == 1){fprintf(stderr, "Error: No parameters specified.\n");return 0;}
    for (i=1; i<argc; i++)
    {
        if (strcmp(argv[i], "-v") == 0)
        {
            v = 1;
        }else if (strcmp(argv[i], "-d") == 0)
        {
            d = 1;
        }else
        {
            file = argv[i];
            f = i;
        }
    }

    heap *h = newHeap();
    h->type = d;
    if (f)
    {
        importFile(h,argv[f]);
    } else if (d == 1 && f == 0)
    {
        fprintf(stderr, "Error: Invalid parameter combination.\n");
        return 0;
    }
    if (v)
    {
        printf(info);
    }
    heapify(h);
    printHeap(h);
    printf("\n");
    
    return 0;
}
