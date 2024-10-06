#ifndef CREATE_LEAF
#define CREATE_LEAF

#include "tree.h"

// Leaf *find_last(Node *ancestor)
// {
//     assert(ancestor);
//     if (!ancestor->right)
//         return;

//     Leaf *curr;
//     curr = ancestor;
//     while (curr->right)
//         curr = curr->right;
//     return curr;
// }
Leaf *create_leaf(Node *ancestor, int8 *key, int8 *value, int16 size)
{
    assert(ancestor);
    Leaf *leaf;
    Leaf *curr;
    curr = (Leaf *)ancestor;

    int16 leaf_size = sizeof(Leaf);
    // printf("GOT HERE leaf size:%d\n", leaf_size);

    leaf = (Leaf *)malloc(leaf_size);
    if (leaf)
    {
        printf("LEAF CREATED\n");
    }
    if (!leaf)
    {
        printf("LEAF MALLOC FAILED\n");
        exit(1);
    }
    // assert_perror(errno);
    // assert(leaf);

    while (curr->right)
        curr = curr->right;

    if (!ancestor->right)
    {
        leaf->left = (Tree *)ancestor;
        ancestor->right = leaf;
    }
    else
    {
        // printf("CURRENT LEAF ADDR %p:\n", curr);
        leaf->left = (Tree *)curr;
        curr->right = leaf;
    }

    // zero_out((int8 *)leaf, leaf_size);
    memset((int8 *)leaf, 0, leaf_size);
    leaf->tag = TagLeaf;
    strncpy((char *)leaf->key, (char *)key, 127);

    leaf->value = (int8 *)malloc(size);
    assert(leaf->value);
    // zero_out(leaf->value, size);
    memset(leaf->value, 0, size);
    strncpy((char *)leaf->value, (char *)value, size);
    leaf->size = size;

    return leaf;
}

void free_leaf(Leaf *l)
{
    free(l->value);
    l->value = NULL;
    free(l);
    l = NULL;
}
#endif // !CREATE_LEAF
