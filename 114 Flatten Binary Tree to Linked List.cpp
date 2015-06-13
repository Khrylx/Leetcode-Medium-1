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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* initTreeRoot(int val)
{
    return new TreeNode(val);
}

TreeNode* addLeftChild(TreeNode* node, int val)
{
    TreeNode* lChild = new TreeNode(val);
    node->left = lChild;
    return lChild;
}

TreeNode* addRightChild(TreeNode* node, int val)
{
    TreeNode* rChild = new TreeNode(val);
    node->right = rChild;
    return rChild;
}

void destroyTree(TreeNode* root)
{
    if (root->left) {
        destroyTree(root->left);
    }
    if (root->right) {
        destroyTree(root->right);
    }
    
    delete root;
    
}

void inorderPrint(TreeNode* root)
{
    if (root->left) {
        inorderPrint(root->left);
    }
    
    cout << root->val <<" ";
    
    if (root->right) {
        inorderPrint(root->right);
    }
}

TreeNode* pre = NULL;

void flatten(TreeNode* root)
{
    if(!root)
        return;
    
    if (pre) {
        pre->left = NULL;
        pre->right = root;
    }
    pre = root;
    
    TreeNode* rChild = root->right;
    if (root->left) {
        flatten(root->left);
    }
    
    if (root->right) {
        flatten(rChild);
    }
}

int main(){
    
    TreeNode* root = initTreeRoot(5);
    TreeNode* n1 = addLeftChild(root, 4);
    TreeNode* n2 = addRightChild(root, 8);
    TreeNode* n3 = addLeftChild(n1, 11);
    TreeNode* n4 = addLeftChild(n2, 13);
    TreeNode* n5 = addRightChild(n2, 4);
    addLeftChild(n3, 7);
    addRightChild(n3, 2);
    addLeftChild(n5, 5);
    addRightChild(n5, 1);
    
    flatten(root);
    //cout << hasPathSum(root, 4) <<endl;
    
    destroyTree(root);
    return 1;
}
