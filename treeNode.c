#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"

static node *newNode(void);

/******** public **********/

node *
newHeapNode(int i, node *parent, node *left, node *right)
{
    node *n = newNode();
    n->value = i;
    n->parent = parent;
    n->left = left;
    n->right = right;
    return n;
}

/********* private ********/

static node *
newNode()
{
    node *n = (node *) malloc(sizeof(node));
    if (n==0) { fprintf(stderr,"out of memory"); exit(-1); }
    return n;
}
