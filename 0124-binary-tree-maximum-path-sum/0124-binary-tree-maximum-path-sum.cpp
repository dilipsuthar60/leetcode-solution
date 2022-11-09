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
    int find(TreeNode*root,int &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        auto left=find(root->left,ans);
        auto right=find(root->right,ans);
        ans=max(ans,left+right+root->val);
        return max({root->val,left+root->val,right+root->val,0});
    }
    int maxPathSum(TreeNode* root) 
    {
        int ans=-1e9;
        find(root,ans);
        return ans;
    }
};