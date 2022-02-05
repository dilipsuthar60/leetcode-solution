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
    ListNode*merge(ListNode*a,ListNode*b)
    {
        if(a==NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        ListNode*c;
        if(a->val<b->val)
        {
            c=a;
            c->next=merge(a->next,b);
        }
        else
        {
            c=b;
            c->next=merge(a,b->next);
        }
        return c;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode*start=NULL;
        ListNode*end=start;
        for(auto it:lists)
        {
            end=merge(end,it);
        }
        return end;
    }
};