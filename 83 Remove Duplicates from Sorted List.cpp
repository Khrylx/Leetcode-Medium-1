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

ListNode* deleteDuplicates(ListNode* head)
{
    if(!head || !(head->next))
        return head;
    
    ListNode* tail = head;
    ListNode* curL = head->next;
    
    while (curL) {
        if (curL->val == tail->val) {
            tail->next = curL->next;
            delete curL;
            curL = tail->next;
        }
        else{
            tail = curL;
            curL = curL->next;
        }
    }
    
    return head;
}

int main(){
    
    ListNode* head = createList();
    deleteDuplicates(head);
    printList(head);
    destroyList(head);
    
    
    return 1;
}

