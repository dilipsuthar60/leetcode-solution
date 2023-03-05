class Solution {
public:
    void find(TreeNode*root,vector<long long>&v,int level=0)
    {
        if(root==NULL)
        {
            return ;
        }
        if(v.size()==level)
        {
            v.push_back(0);
        }
        v[level]+=root->val;
        find(root->left,v,level+1);
        find(root->right,v,level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        vector<long long>v;
        find(root,v);
        if(v.size()<k)
        {
            return -1;
        }
        sort(v.begin(),v.end(),greater<long long>());
        return v[k-1];
    }
};