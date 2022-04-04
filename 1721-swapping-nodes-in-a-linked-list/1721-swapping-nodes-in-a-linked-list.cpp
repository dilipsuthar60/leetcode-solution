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
    ListNode* swapNodes(ListNode* head, int k) {
         if(head==NULL)
        {
            return head;
        }
        int count=0;
        ListNode*node=head;
        while(node!=NULL)
        {
            count++;
            node=node->next;
        }
        count=count-k;
        k--;
        ListNode*head1=head;
        ListNode*head2=head;
        while(k--)
        {
            head1=head1->next;
        }
        while(count--)
        {
            head2=head2->next;
        }
        swap(head1->val,head2->val);
        return head;
    }
};