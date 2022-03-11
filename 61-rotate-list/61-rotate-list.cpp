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
    int find(ListNode*head)
    {
        int count=0;
        for(;head;head=head->next)
        {
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        if(k==0)
        {
            return head;
        }
        int len=find(head);
        ListNode*curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=head;
        k=k%len;
        k=len-k-1;
        while(k--)
        {
            head=head->next;
        }
        ListNode*ans=head->next;
        head->next=NULL;
        return ans;
        
    }
};