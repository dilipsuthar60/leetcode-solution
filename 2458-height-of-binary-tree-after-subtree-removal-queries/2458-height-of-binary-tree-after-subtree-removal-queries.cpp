class Solution {
public:
    int in[300005],out[300005],prefix[300005],suffix[300005];
    int depth[300005];
    int time=1;
    void find(TreeNode*root,int d)
    {
        if(root==NULL)
        {
            return ;
        }
        depth[time]=d;
        in[root->val]=time++;
        find(root->left,d+1);
        find(root->right,d+1);
        out[root->val]=time++;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& q) 
    {
        find(root,0);
        for(int i=1;i<300005;i++)
        {
            prefix[i]=max(prefix[i-1],depth[i]);
        }
        for(int i=300003;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],depth[i]);
        }
        vector<int>ans;
        for(auto it:q)
        {
            int val=max(prefix[in[it]-1],suffix[out[it]+1]);
            ans.push_back(val);
        }
        return ans;
    }
};