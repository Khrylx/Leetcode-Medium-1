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

TreeNode* buildTreeHelper(vector<int>& preorder,vector<int>& inorder,int l1,int u1,int l2,int u2)
{
    if (l1 >= u1) {
        return NULL;
    }
    
    TreeNode* node = new TreeNode(preorder[l1]);
    
    int i = l2;
    for (i = l2; i < u2; i++) {
        if (inorder[i] == preorder[l1]) {
            break;
        }
    }
    int j = l1+i-l2+1;
    
    node->left = buildTreeHelper(preorder, inorder, l1+1, j, l2, i);
    node->right = buildTreeHelper(preorder, inorder, j, u1, i+1, u2);
    
    return node;
    
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return buildTreeHelper(preorder,inorder,0,(int)preorder.size(),0,(int)inorder.size());
}

int main(){
    
    int N;
    cin >> N;
    vector<int> preorder(N);
    vector<int> inorder(N);
    for (int i = 0; i < N; i++) {
        cin >> preorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    TreeNode* tree = buildTree(preorder, inorder);
    inorderPrint(tree);
    destroyTree(tree);
    return 1;
}