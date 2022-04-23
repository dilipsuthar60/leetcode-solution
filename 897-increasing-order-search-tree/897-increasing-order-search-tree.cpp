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
    TreeNode*curr;
    void find(TreeNode*root)
    {
        if(root==NULL)
        {
            return ;
        }
        find(root->left);
        root->left=NULL;
        curr->right=root;
        curr=root;
        find(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) 
    {
        TreeNode*ans;
        curr=new TreeNode(-1);
        ans=curr;
        find(root);
        return ans->right;
    }
};