class Solution {
public:
    TreeNode* find(vector<int>&v,int l,int r)
    {
        if(l>r)
            return NULL;
        int mid=(l+r)/2;
        TreeNode *root=new TreeNode(v[mid]);
        root->left=find(v,l,mid-1);
        root->right=find(v,mid+1,r);
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int>v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        return find(v,0,v.size()-1);
    }
};