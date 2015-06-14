//
//  main.cpp
//  Leetcode
//
//  Created by Eric on 15/5/14.
//  Copyright (c) 2015年 Eric. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* initTreeRoot(int val)
{
    return new TreeLinkNode(val);
}

TreeLinkNode* addLeftChild(TreeLinkNode* node, int val)
{
    TreeLinkNode* lChild = new TreeLinkNode(val);
    node->left = lChild;
    return lChild;
}

TreeLinkNode* addRightChild(TreeLinkNode* node, int val)
{
    TreeLinkNode* rChild = new TreeLinkNode(val);
    node->right = rChild;
    return rChild;
}

void destroyTree(TreeLinkNode* root)
{
    if (root->left) {
        destroyTree(root->left);
    }
    if (root->right) {
        destroyTree(root->right);
    }
    
    delete root;
    
}

void inorderPrint(TreeLinkNode* root)
{
    if (root->left) {
        inorderPrint(root->left);
    }
    
    cout << root->val <<" ";
    
    if (root->right) {
        inorderPrint(root->right);
    }
}

void connectHelper(TreeLinkNode *n1, TreeLinkNode *n2)
{
    n1->next = n2;
    if (!n1->left) {
        return;
    }
    
    connectHelper(n1->left, n1->right);
    connectHelper(n2->left, n2->right);
    connectHelper(n1->right, n2->left);
}

void connect(TreeLinkNode *root)
{
    if (!root) {
        return;
    }
    
    if (root->left) {
        connectHelper(root->left, root->right);
    }
}


int main(){
    

    
    return 1;
}
