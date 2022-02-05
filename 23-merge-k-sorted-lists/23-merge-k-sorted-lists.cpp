
class Solution {
public:
    ListNode*merge(ListNode*l1,ListNode*l2)
    {
        if(l1==NULL||l2==NULL)
        {
            return l1==NULL?l2:l1;
        }
        ListNode*dummy_node=new ListNode(-1);
        ListNode*head=dummy_node;
        while(l1!=NULL&&l2!=NULL)
        {
            if((l1->val)<(l2->val))
            {
                dummy_node->next=l1;
                l1=l1->next;
            }
            else
            {
                dummy_node->next=l2;
                l2=l2->next;
            }
            dummy_node=dummy_node->next;
        }
        dummy_node->next=(l1==NULL)?l2:l1;
        return head->next;
    }
    ListNode*find(vector<ListNode*>&nums,int l,int r)
    {
        if(l==r)
        {
            return nums[l];
        }
        int mid=l+(r-l)/2;
        ListNode*left=find(nums,l,mid);
        ListNode*right=find(nums,mid+1,r);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return NULL;
        }
        return find(lists,0,lists.size()-1);
    }
};