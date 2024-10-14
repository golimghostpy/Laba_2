#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include "libs.h"

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value): data(value), left(nullptr), right(nullptr){}
};

struct BinTree{
    TreeNode* root;

    BinTree(): root(nullptr){}

    void insert(int);
    void remove(int);
    void print_tree(TreeNode*, int, int);
};

#endif // BINARYSEARCHTREE_H_INCLUDED
