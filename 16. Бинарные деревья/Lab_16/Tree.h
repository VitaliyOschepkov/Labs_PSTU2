#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Tree
{
    char key;
    Tree* left;
    Tree* right;
    int height;
};
int Height(Tree* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
int Max(int a, int b)
{
    return (a > b) ? a : b;
}
Tree* newTree(char key)
{
    Tree* root = new Tree();
    root->key = key;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;
    return root;
}
Tree* turnRight(Tree* root)
{
    Tree* tmp1 = root->left;
    Tree* tmp2 = tmp1->right;
    tmp1->right = root;
    root->left = tmp2;
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    tmp1->height = Max(Height(tmp1->left), Height(tmp1->right)) + 1;
    return tmp1;
}
Tree* turnLeft(Tree* root)
{
    Tree* tmp1 = root->right;
    Tree* tmp2 = tmp1->left;
    tmp1->left = root;
    root->right = tmp2;
    root->height = Max(Height(root->left), Height(root->right)) + 1;
    tmp1->height = Max(Height(tmp1->left), Height(tmp1->right)) + 1;
    return tmp1;
}
int getBalance(Tree* root)
{
    if (root == NULL)
        return 0;
    return (Height(root->left) - Height(root->right));
}
Tree* Insert(Tree* root, char key)
{
    if (root == NULL)
        return(newTree(key));
    if (key < root->key)
        root->left = Insert(root->left, key);
    else if (key > root->key)
        root->right = Insert(root->right, key);
    else     
        return root;
    root->height = 1 + Max(Height(root->left), Height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && key < root->left->key)
        return turnRight(root);
    if (balance < -1 && key > root->right->key)
        return turnLeft(root);
    if (balance > 1 && key > root->left->key)
    {
        root->left = turnLeft(root->left);
        return turnRight(root);
    }
    if (balance < -1 && key < root->right->key)
    {
        root->right = turnRight(root->right);
        return turnLeft(root);
    }
    return root;
}
void Print(Tree* root, int height)
{
    if (root != nullptr)
    {
        Print(root->right, height + 1);

        for (int i = 0; i < 5 * height; i++)
            cout << " ";

        cout << root->key << "\n";
        Print(root->left, height + 1);
    }
}
Tree* elementAdd(Tree* root)
{
    char key;
    cout << "\n¬ведите букву" << endl;
    cout << "\n> ";
    cin >> key;
    root = Insert(root, key);
    return root;
}
Tree* Generate()
{
    Tree* root = NULL;
    char key;
    int size;
    cout << "¬ведите количество элементов: ";
    cin >> size;
    for (int i = 0; i < size; i++)
        root = elementAdd(root);
    return root;
}
void Count(Tree* root, int& counter, char key)
{
    if (root != NULL)
    {
        if (root->key == key)
            counter++;
        Count(root->right, counter, key);
        Count(root->left, counter, key);
    }
}