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
    ListNode*root,*curr;
    int count=0;
    Solution(ListNode* head) 
    {
        root=head;
        for(ListNode*now=head;now!=NULL;now=now->next)
        {
            count++;
        }
    }
    
    int getRandom() 
    {
        int position=rand()%count;
        curr=root;
        while(position--)
        {
            curr=curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */