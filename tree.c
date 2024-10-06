#include "tree.h"
#include "create_leaf.h"

Tree root = {
    .n = {
        .tag = (TagRoot | TagNode),
        .up = (Tree *)&root,
        .left = NULL,
        .right = NULL,
        .path = "/"
    }
};

Node *create_node(Node *parent, int8 *path)
{
    Node *n;
    int16 size;

    assert(parent);
    size = sizeof(struct s_node);
    n = (Node *)malloc(size);
    // zero_out((int8 *)n, size);
    memset((int8 *)n, 0, size);

    parent->left = n;
    n->tag = TagNode;
    n->up = (Tree *)parent;
    strncpy((char *)n->path, (char *)path, 255);

    return n;
}

int main()
{
    printf("%p\n", &root);
    Node *n;
    Node *n2;
    Leaf *l1;
    Leaf *l2;
    int8 *key;
    int8 *value;
    int16 size;
    n = create_node((Node *)&root, (int8 *)"/Users");
    assert(n);
    n2 = create_node(n, (int8 *)"Users/login");
    assert(n2);

    printf("%p %p\n", n, n2);

    key = (int8 *)"Customer1";
    value = (int8 *)"Cookie";
    size = (int16)strlen((char *)value);

    l1 = create_leaf(n2, key, value, size);
    assert(l1);
    printf("val:%s\nkey:%s\n", l1->value, l1->key);

    key = (int8 *)"Cust";
    value = (int8 *)"Som";
    size = (int16)strlen((char *)value);

    l2 = create_leaf(n2, key, value, size);
    assert(l2);
    printf("val:%s\nkey:%s\n", l2->value, l2->key);

    free_leaf(l2);
    free_leaf(l1);
    free(n2);
    free(n);
    n2 = NULL;
    n = NULL;

    return 0;
}