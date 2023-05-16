class Solution {
public:
    void find(ListNode*node,ListNode*&th,ListNode*&tt)
    {
        if(th==NULL)
        {
            th=tt=node;
        }
        else
        {
            node->next=th;
            th=node;
        }
    }
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode*curr=head;
        ListNode*oh,*ot,*th,*tt;
        oh=ot=th=tt=NULL;
        while(curr)
        {
            int tp=2;
            while(tp--&&curr)
            {
                ListNode*temp=curr->next;
                curr->next=NULL;
                find(curr,th,tt);
                curr=temp;
            }
            if(oh==NULL)
            {
                oh=th;
                ot=tt;
            }
            else
            {
                ot->next=th;
                ot=tt;
            }
            th=tt=NULL;
        }
        return oh;
    }
};