/*************************************************************************
	> File Name: AddTwoNumbers.cpp
	> Author: CWen
	> Mail: yincwengo@gmail.com
	> Created Time: 2016年02月03日 星期三 22时13分29秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insert(ListNode *head, int x) {
    ListNode* cur = head;
    while(cur->next != NULL) {
        cur = cur->next;
    }
    ListNode* newNode = new ListNode(x);
    cur->next = newNode;
}

void traverse(ListNode *head) {
    ListNode* cur = head;
    while(cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
}

ListNode *addTwoNumbers(ListNode *l1,ListNode *l2) {
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }   
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    int carry = 0,num = 0;
    ListNode *cur = new ListNode(-1);
    ListNode *sum = cur;
    while(l1 != NULL && l2 != NULL) {
        num = l1->val + l2->val + carry;
        carry = num / 10;
        num = num % 10;
        l1->val = num;
        cur->next = l1;
        cur = cur->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL) {
        num = l1->val + carry;
        carry = num / 10;
        num = num % 10;
        l1->val = num;
        cur->next = l1;
        cur = cur->next;
        l1 = l1->next;
    }
    while(l2 != NULL) {
        num = l2->val + carry;
        carry = num / 10;
        num = num % 10;
        l2->val = num;
        cur->next = l2;
        cur = cur->next;
        l2 = l2->next;
    }
    if (carry > 0) {
        ListNode *t = new ListNode(carry);
        cur->next = t;
    }
    return sum->next;
}

int main() {
    ListNode *head1 = new ListNode(2);
    ListNode *head2 = new ListNode(5);
    int a[] = {4,3};
    int b[] = {6,4};
    for (int i = 0; i < 2; i++) {
        insert(head1,a[i]);
        insert(head2,b[i]);
    }
    traverse(addTwoNumbers(head1,head2));
    return 0;
}

