#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void leftnodes(TreeNode<int> *root, vector<int> &v)
{
    if (root == nullptr)
        return;

    if (root->left)
    {
        v.push_back(root->data);
        leftnodes(root->left, v);
    }
    else if (root->right)
    {
        v.push_back(root->data);
        leftnodes(root->right, v);
    }
}

void rightnodes(TreeNode<int> *root, vector<int> &v)
{
    if (root == nullptr)
        return;

    if (root->right)
    {
        rightnodes(root->right, v);
        v.push_back(root->data);
    }
    else if (root->left)
    {
        rightnodes(root->left, v);
        v.push_back(root->data);
    }
}

void leafnodes(TreeNode<int> *root, vector<int> &v)
{
    if (root == nullptr)
        return;

    leafnodes(root->left, v);

    if (!(root->left || root->right))
    {
        v.push_back(root->data);
    }

    leafnodes(root->right, v);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{

    vector<int> v;
    if (root == nullptr)
        return v;

    v.push_back(root->data);
    leftnodes(root->left, v);
    leafnodes(root->left, v);
    leafnodes(root->right, v);
    rightnodes(root->right, v);

    return v;
}