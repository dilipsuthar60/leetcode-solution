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
    int ans=0;
    vector<int>find(TreeNode*root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        auto left=find(root->left);
        auto right=find(root->right);
        vector<int>v(2);
        v[0]=1+left[1];
        v[1]=1+right[0];
        ans=max({ans,left[1],right[0]});
        return v;
    }
    int longestZigZag(TreeNode* root)
    {
        find(root);
        return ans;
    }
};