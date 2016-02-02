typedef struct tree_node_obj
    {
        int value;
        struct node *parent;
        struct node *left;
        struct node *right;
    } treeNode;

extern treeNode *newTreeNode(int value, treeNode *parent, treeNode *left, treeNode *right);
