#include "BinarySearchTree.h"

void BinTree::insert(int value){
    if (root == nullptr){
        root = new TreeNode(value);
        return;
    }

    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while(current != nullptr){
        parent = current;
        if (value < current->data) current = current->left;
        else current = current->right;
    }

    if (value < parent->data) parent->left = new TreeNode(value);
    else parent->right = new TreeNode(value);
}

void BinTree::remove(int value){
    if (root == nullptr){
        cout << "Tree is empty" << endl;
        return;
    }

    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while (current != nullptr && current->data != value){
        parent = current;
        if (value < current->data) current = current->left;
        else current = current->right;
    }

    if (current == nullptr) {
        cout << "No such a value" << endl;
        return;
    }

    if (current->left == nullptr && current->right == nullptr){
        if (parent == nullptr) root = nullptr;
        else if (parent->left == current) parent->left = nullptr;
        else parent->right = nullptr;

        delete current;
        return;
    }

    if (current->left == nullptr){
        if (parent == nullptr) root = current->right;
        else if (parent->left == current) parent->left = current->right;
        else parent->right = current->right;

        delete current;
        return;
    }

    if (current->right == nullptr){
        if (parent == nullptr) root = current->left;
        else if (parent->left == current) parent->left = current->left;
        else parent->right = current->left;

        delete current;
        return;
    }

    TreeNode* successor = current->right;
    parent = current;
    while (successor->left != nullptr){
        parent = successor;
        successor = successor->left;
    }

    current->data = successor->data;

    if (parent->left == successor) parent->left = successor->right;
    else parent->right = successor->right;

    delete successor;
}

void BinTree::print_tree(TreeNode* node, int space, int indent){
    if (node == nullptr)
        return;

    space += indent;

    print_tree(node->right, space, indent);

    for (int i = indent; i < space; ++i)
        cout << " ";
    cout << node->data << "\n";

    print_tree(node->left, space, indent);
}
