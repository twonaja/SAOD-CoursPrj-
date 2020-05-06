#include "avl.h"

void BST::makeEmpty(node* t)
{
    {
        if (t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
}

BST::node* BST::insert(int x, node* t)
{
    if (t == nullptr)
    {
        t = new node;
        t->data = x;
        t->height = 0;
        t->left = t->right = nullptr;
    }
    else if (x < t->data)
    {
        t->left = insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
        {
            if (x < t->left->data)
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if (x > t->data)
    {
        t->right = insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
        {
            if (x > t->right->data)
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }
    t->height = std::max(height(t->left), height(t->right)) + 1;
    return t;
}

BST::node* BST::singleRightRotate(node*& t)
{
    node* u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    u->height = std::max(height(u->left), t->height) + 1;
    return u;
}

BST::node* BST::singleLeftRotate(node*& t)
{
    node* u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    u->height = std::max(height(t->right), t->height) + 1;
    return u;
}

BST::node* BST::doubleLeftRotate(node*& t)
{
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

BST::node* BST::doubleRightRotate(node*& t)
{
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

BST::node* BST::findMin(node* t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return findMin(t->left);
}

BST::node* BST::findMax(node* t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    else
        return findMax(t->right);
}

BST::node* BST::remove(int x, node* t)
{
    node* temp;

    // Element not found
    if (t == nullptr)
    { 
        return nullptr;
    }
    // Searching for element
    else if (x < t->data)
    {
        t->left = remove(x, t->left);
    }
    else if (x > t->data)
    {
        t->right = remove(x, t->right);
    }
    // Element found
    // With 2 children
    else if (t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    // With one or zero child
    else
    {
        temp = t;
        if (t->left == nullptr)
            t = t->right;
        else if (t->right == nullptr)
            t = t->left;
        delete temp;
    }
    if (t == nullptr)
    {
        return t;
    }
    t->height = std::max(height(t->left), height(t->right)) + 1;

    // If node is unbalanced
    // If left node is deleted, right case
    if (height(t->left) - height(t->right) == 2)
    {
        // right right case
        if (height(t->left->left) - height(t->left->right) == 1)
            return singleLeftRotate(t);
        // right left case
        else
            return doubleLeftRotate(t);
    }
    // If right node is deleted, left case
    else if (height(t->right) - height(t->left) == 2)
    {
        // left left case
        if (height(t->right->right) - height(t->right->left) == 1)
            return singleRightRotate(t);
        // left right case
        else
            return doubleRightRotate(t);
    }
    return t;
}

int BST::height(node* t)
{
    return (t == nullptr ? -1 : t->height);
}

int BST::getBalance(node* t)
{
    if (t == nullptr)
        return 0;
    else
        return height(t->left) - height(t->right);
}

void BST::inorder(node* t)
{
    if (t == nullptr)
        return;
    inorder(t->left);
    std::cout << t->data << " ";
    inorder(t->right);
}

BST::BST()
{
    root = nullptr;
}

void BST::insert(int x)
{
    root = insert(x, root);
}

void BST::remove(int x)
{
    root = remove(x, root);
}

void BST::display()
{
    inorder(root);
    std::cout << std::endl;
}