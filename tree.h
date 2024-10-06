#ifndef TREE_H
#define TREE_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <assert.h>
#include <errno.h>
#include <assert.h>
#include <sys/random.h>

#define TagRoot 1
#define TagNode 2
#define TagLeaf 4

typedef unsigned char Tag;
typedef uint8_t int8;
typedef uint16_t int16;

typedef struct s_node
{
    Tag tag;
    union u_tree *up;
    // struct s_node *right;
    struct s_leaf *right;
    struct s_node *left;
    int8 path[256];
} Node;

typedef struct s_leaf
{
    // Leaf right;
    Tag tag;
    union u_tree *left;
    struct s_leaf *right;
    int8 key[128];
    int8 *value;
    int16 size;
} Leaf;

typedef union u_tree
{
    Node n;
    Leaf l;
} Tree;

void zero_out(int8 *, int16 size);
Leaf *create_leaf(Node *ancestor, int8 *key, int8 *value, int16 size);
void free_leaf(Leaf *);
Node *create_node(Node *parent, int8 *path);

void zero_out(int8 *str, int16 size)
{
    int8 *p;
    int16 n;
    for (n = 0, p = str; n < size; p++, n++)
        *p = 0;
}

#endif // !TREE_H