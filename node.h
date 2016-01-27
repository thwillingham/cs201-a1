typedef struct node
    {
        int value;
        struct node *parent;
        struct node *left;
        struct node *right;
    } node;

extern node *newNode(int value, node *parent, node *left, node *right);
