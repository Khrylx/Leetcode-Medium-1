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

TreeNode* sortedArrayToBSThelper(vector<int>& nums,int bIndex,int eIndex)
{
    if (bIndex > eIndex) {
        return NULL;
    }
    
    int mid = (bIndex+eIndex)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    
    if (eIndex > bIndex) {
        node->left = sortedArrayToBSThelper(nums,bIndex,mid-1);
        node->right = sortedArrayToBSThelper(nums,mid+1,eIndex);
    }
    
    return node;

}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return sortedArrayToBSThelper(nums, 0, (int)nums.size()-1);
}

int main(){
    
    int N;
    cin >> N;
    vector<int> nums(N);
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    TreeNode* tree = sortedArrayToBST(nums);
    inorderPrint(tree);
    destroyTree(tree);
    return 1;
}