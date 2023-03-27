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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode*temp=head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        int move=len-n;
        temp=head;
        if(len==n)
        {
            return head->next;
        }
        while(move>1)
        {
            temp=temp->next;
            move--;
        }
        temp->next=(temp->next->next);
        return head;
    }
};    