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
    ListNode*mergelist(ListNode*l1,ListNode*l2)
    {
        if(l1==NULL||l2==NULL) return l1==NULL?l2:l1;
        ListNode*newHead=new ListNode(-1);
        ListNode*newTail=newHead;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                newTail->next=l1;
                l1=l1->next;
            }
            else
            {
                newTail->next=l2;
                l2=l2->next;
            }
            newTail=newTail->next;
        }
        newTail->next=(l1==NULL)?l2:l1;
        return newHead->next;
    }
    ListNode*find(vector<ListNode*>&list,int l,int r)
    {
        if(l==r)
        {
            return list[l];
        }
        int mid=(l+r)/2;
        return mergelist(find(list,l,mid),find(list,mid+1,r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0) return NULL;
        return find(lists,0,lists.size()-1);
    }
};