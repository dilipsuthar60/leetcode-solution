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
    ListNode* reverseKGroup(ListNode* head, int k)         
    {
        int len=0;
        ListNode*curr=head;
        ListNode*oh,*ot,*th,*tt;
        oh=ot=th=tt=NULL;
        for(;head!=NULL;head=head->next,len++);
        while(len>=k)
        {
            int tempk=k;
            while(tempk--)
            {
                ListNode* f=curr->next;
                curr->next=NULL;
                find(curr,th,tt);
                curr=f;
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
            th=NULL;
            tt=NULL;
            len-=k;
        }
        ot->next=curr;
        return oh;
    }
};