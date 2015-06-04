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

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if (!head || !(head->next) || m == n) {
        return head;
    }
    
    ListNode* tail = NULL;
    ListNode* p1;
    ListNode* p2;
    ListNode* p3;
    
    int index = m;
    
    if (m == 1) {
        p1 = head;
    }
    else{
        tail = head;
        for (int i = 0; i < m-2; i++) {
            tail = tail->next;
        }
        p1 = tail->next;
    }
    
    ListNode* newTail = p1;
    
    p2 = p1->next;
    while (index < n) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        index++;
    }
    
    if (m == 1) {
        head = p1;
    }
    else{
        tail->next = p1;
    }
    
    newTail->next = p2;
    
    return head;
}


int main(){
    
    ListNode* head = createList();
    head = reverseBetween(head, 1, 4);
    printList(head);
    destroyList(head);
    
    return 1;
}



