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
    void find(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)
        {
            return ;
        }
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }
    int minDiffInBST(TreeNode* root) 
    {
        vector<int>v;
        find(root,v);
        int min_diff=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            min_diff=min(min_diff,abs(v[i]-v[i-1]));
        }
        return min_diff;
    }
};