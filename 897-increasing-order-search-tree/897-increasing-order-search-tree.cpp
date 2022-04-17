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
    void find(TreeNode*root,vector<int>&v)
    {
        if(root==NULL)
        {
            return ;
        }
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        vector<int>v;
        find(root,v);
        TreeNode*start=new TreeNode(v[0]);
        TreeNode*end=start;
        for(int i=1;i<v.size();i++)
        {
            end->right=new TreeNode(v[i]);
            end=end->right;
        }
        return start;
    }
};