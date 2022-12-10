/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long mod=1e9+7;
    long long ans=0;
    void find(TreeNode*root,int &sum)
    {
        if(root==NULL)
        {
            return ;
        }
         sum+=root->val;
        find(root->left,sum);
        find(root->right,sum);
    }
    int cut(TreeNode*root,int sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=cut(root->left,sum);
        int right=cut(root->right,sum);
        int val=left+right+root->val;
        ans=max(ans,1ll*(sum-val)*val);
        return val;
    }
    int maxProduct(TreeNode* root) 
    {
        ans=0;
        int total_sum=0;
        find(root,total_sum);
        // cout<<total_sum<<endl;
        cut(root,total_sum);
        return ans%mod;
    }
};