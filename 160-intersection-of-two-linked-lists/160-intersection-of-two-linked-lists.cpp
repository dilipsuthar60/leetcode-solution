/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int get_len(ListNode *root)
    {
        int len=0;
        for(;root;root=root->next)
        {
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) 
    {
        int len1=get_len(head1);
        int len2=get_len(head2);
        int move1=max(0,len1-len2);
        int move2=max(0,len2-len1);
        while(move1--)
        {
            head1=head1->next;
        }
        while(move2--)
        {
            head2=head2->next;
        }
        while(head1!=head2)
        {
            head1=head1->next;
            head2=head2->next;
        }
        return head1;
    }
};