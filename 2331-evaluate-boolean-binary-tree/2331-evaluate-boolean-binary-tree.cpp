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
    bool find(TreeNode*root)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            if(root->val==1)
            {
                return true;
            }
            return false;
        }
        bool left=find(root->left);
        bool right=find(root->right);
        return (root->val==2)?left||right:left&&right;
    }
    bool evaluateTree(TreeNode* root) 
    {
        return find(root);
    }
};