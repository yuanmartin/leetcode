// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem148.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
    {
        ListNode *dummy = new ListNode(0), *p = dummy;
        while (l1 && l2)
        {
            if(l1->val >= l2->val)
            {
                p->next = l2;
                l2 = l2->next;
            }
            else
            {
                p->next = l1;
                l1=l1->next;
            }
            p = p->next;
        }

        if(l1)
        {
            p->next = l1;
        }
            
        if(l2)
        {
            p->next = l2;
        }
            
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) 
    {
      if(!head || !head->next)
            return head;
        ListNode *fast=head, *slow=head, *pre=head;
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next=nullptr;
        head = sortList(head);
        slow = sortList(slow);
        return mergeTwoLists(head,slow);
    }
};
// @lc code=end

