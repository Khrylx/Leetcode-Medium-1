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
    
    cout << root->val << " ";
    
    if (root->right) {
        inorderPrint(root->right);
    }
    


}

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> solutions;
    
    if (!root) {
        return solutions;
    }
    
    stack<TreeNode*> S;
    TreeNode* node = root;
    S.push(node);
    while (node->left) {
        node = node->left;
        S.push(node);
    }

    
    while (!S.empty()) {
        node = S.top();
        S.pop();
        
        solutions.push_back(node->val);
        if (node->right) {
            node = node->right;
            S.push(node);
            while (node->left) {
                node = node->left;
                S.push(node);
            }
        }
    }
    
    return solutions;
}



int main(){
    
    TreeNode* root = initTreeRoot(1);
    TreeNode* n1 = addLeftChild(root, 2);
    TreeNode* n2 = addRightChild(root, 3);
    TreeNode* n3 = addLeftChild(n1, 4);
    TreeNode* n4 = addRightChild(n1, 5);
    
    inorderPrint(root);
    cout << endl;
    
    vector<int> solutions = inorderTraversal(root);
    for (int i = 0; i < solutions.size(); i++) {
        cout << solutions[i] << " ";
    }
    
    destroyTree(root);
    return 1;
}



