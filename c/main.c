#include <stdio.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *root = 0;



/* program flow:
 * 1) import data into tree
 * 2) heapify tree
 * 3) output integers
 */
