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

void pathSumHelper(TreeNode* root, int sum, vector<int>& curPath, vector<vector<int>>& solutions)
{
    if(!root)
        return;
    
    
    if (root->left && root->right) {
        curPath.push_back(root->val);
        pathSumHelper(root->left, sum-root->val,curPath,solutions);
        pathSumHelper(root->right, sum-root->val,curPath,solutions);
        curPath.pop_back();
    }
    else if(root->left && !root->right){
        curPath.push_back(root->val);
        pathSumHelper(root->left, sum-root->val,curPath,solutions);
        curPath.pop_back();
    }
    else if(root->right && !root->left){
        curPath.push_back(root->val);
        pathSumHelper(root->right, sum-root->val,curPath,solutions);
        curPath.pop_back();
    }
    else if(root->val == sum){
        curPath.push_back(sum);
        solutions.push_back(curPath);
        curPath.pop_back();
    }
    
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> solutions;
    vector<int> curPath;
    
    pathSumHelper(root, sum, curPath, solutions);
    
    return solutions;
    
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
    
    vector<vector<int>> paths = pathSum(root, 22);
    //cout << hasPathSum(root, 4) <<endl;
    
    destroyTree(root);
    return 1;
}
