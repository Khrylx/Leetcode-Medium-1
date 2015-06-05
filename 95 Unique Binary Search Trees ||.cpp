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

void destroyTree(TreeNode* root)
{
    if (!root) {
        return;
    }
    
    if (root->left) {
        destroyTree(root->left);
    }
    if (root->right) {
        destroyTree(root->right);
    }
    
    delete root;
    
}

void preorderPrint(TreeNode* root)
{
    
    cout << root->val << " ";
    
    if (root->left) {
        preorderPrint(root->left);
    }
    
    if (root->right) {
        preorderPrint(root->right);
    }
    
}

vector<TreeNode*> generateTreesHelper(int left, int right)
{
    vector<TreeNode*> solutions;
    
    if (left == right) {
        solutions.push_back(new TreeNode(left));
    }
    
    for (int i = left; i <= right; i++) {
        if (i == left) {
            vector<TreeNode*> rTrees = generateTreesHelper(left+1, right);
            for (int j = 0; j < rTrees.size(); j++) {
                solutions.push_back(new TreeNode(i));
                solutions.back()->right = rTrees[j];
            }
        }
        else if (i == right) {
            vector<TreeNode*> lTrees = generateTreesHelper(left, right-1);
            for (int j = 0; j < lTrees.size(); j++) {
                solutions.push_back(new TreeNode(i));
                solutions.back()->left = lTrees[j];
            }
        }
        else{
            vector<TreeNode*> lTrees = generateTreesHelper(left, i-1);
            vector<TreeNode*> rTrees = generateTreesHelper(i+1, right);
            
            for (int j = 0; j < lTrees.size(); j++) {
                for (int k = 0; k < rTrees.size(); k++) {
                    solutions.push_back(new TreeNode(i));
                    solutions.back()->left = lTrees[j];
                    solutions.back()->right = rTrees[k];
                }
            }
        }
    }
    
    return solutions;
}


vector<TreeNode*> generateTrees(int n)
{
    if ( n == 0) {
        vector<TreeNode*> solutions;
        solutions.push_back(NULL);
        return solutions;
    }
    return generateTreesHelper(1, n);
    
}


int main(){
    vector<TreeNode*> trees = generateTrees(3);
    
    for (int i = 0; i < trees.size(); i++) {
        preorderPrint(trees[i]);
        cout << endl;
        
        destroyTree(trees[i]);
    }
    
    
    
    return 1;
}




