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

ListNode* partition(ListNode* head, int x)
{
    if (!head) {
        return head;
    }
    
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    ListNode* tail1 = NULL;
    ListNode* tail2 = NULL;
    
    ListNode* curL = head;
    
    while (curL) {
        if(curL->val < x)
        {
            if (!head1) {
                head1 = curL;
                tail1 = curL;
            }
            else{
                tail1->next = curL;
                tail1 = tail1->next;
            }
        }
        else
        {
            if (!head2) {
                head2 = curL;
                tail2 = curL;
            }
            else{
                tail2->next = curL;
                tail2 = tail2->next;
            }
        }
        
        curL = curL->next;
    }
    
    if (head1 && head2) {
        tail1->next = head2;
        tail2->next = NULL;
        return head1;
    }
    else if(head1 && !head2){
        tail1->next = head2;
        return head1;
    }
    else{
        tail2->next = NULL;
        return head2;
    }
    
    return head1;
}

int main(){
    
    ListNode* head = createList();
    partition(head,3);
    printList(head);
    destroyList(head);
    
    
    return 1;
}

