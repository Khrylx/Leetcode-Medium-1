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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode* createList()
{
    ListNode* head=NULL;
    ListNode* curL=NULL;
    int n;
    
    cin>>n;
    
    for (int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        if (head==NULL)
        {
            head=new ListNode(input);
            curL=head;
        }
        else
        {
            curL->next=new ListNode(input);
            curL=curL->next;
        }
    }
    
    return head;
}

void printList(ListNode* head)
{
    ListNode* curL=head;
    
    while (curL!=NULL)
    {
        cout<<curL->val<<" ";
        curL=curL->next;
    }
    cout<<endl;
}

void destroyList(ListNode* head)
{
    ListNode* curL=head;
    
    while (curL!=NULL)
    {
        ListNode* tmpL=curL;
        curL=curL->next;
        delete tmpL;
    }
}



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

void inorderPrint(TreeNode* root)
{
    if (!root) {
        return;
    }
    if (root->left) {
        inorderPrint(root->left);
    }
    
    cout << root->val <<" ";
    
    if (root->right) {
        inorderPrint(root->right);
    }
}

TreeNode* sortedListToBST(ListNode* head)
{
    if (!head) {
        return NULL;
    }
    
    ListNode* mid = head;
    ListNode* cur = head;
    ListNode* tail = NULL;
    bool add = false;
    
    while (cur) {
        if (add) {
            tail = mid;
            mid = mid->next;
        }
        cur = cur->next;
        add = !add;
    }
    if (tail) {
        tail->next = NULL;
    }
    
    TreeNode* node = new TreeNode(mid->val);
    if (tail) {
        node->left = sortedListToBST(head);
    }
    if (mid->next) {
        node->right = sortedListToBST(mid->next);
    }
    
    return node;
}

int main(){
    
    ListNode* list = createList();
    
    TreeNode* tree = sortedListToBST(list);
    inorderPrint(tree);
    destroyTree(tree);
    destroyList(list);
    
    return 1;
}