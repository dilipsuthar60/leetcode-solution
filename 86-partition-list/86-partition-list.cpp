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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode*l1=new ListNode(-1);
        ListNode*l1start=l1;
        ListNode*l2=new ListNode(-1);
        ListNode*l2start=l2;
        for(;head;head=head->next)
        {
            if(head->val<x)
            {
                l1->next=head;
                l1=l1->next;
            }
            else
            {
                l2->next=head;
                l2=l2->next;
            }
        }
        l1->next=l2start->next;
        l2->next=NULL;
        return l1start->next;
    }
};