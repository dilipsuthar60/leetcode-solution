class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        int i=0;
        ListNode*even=new ListNode(-1);
        ListNode*odd=new ListNode(-1);
        ListNode*dummy_even=even;
        ListNode*dummy_odd=odd;
        for(ListNode*curr=head;curr!=NULL;curr=curr->next,i++)
        {
            if(i%2==0)
            {
                dummy_even->next=curr;
                dummy_even=dummy_even->next;
            }
            else
            {
                dummy_odd->next=curr;
                dummy_odd=dummy_odd->next;
            }
        }
        dummy_even->next=odd->next;
        dummy_odd->next=NULL;
        return even->next;
    }
};