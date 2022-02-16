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
    int countNodes(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=0;
        int rh=0;
        TreeNode*root_l=root;
        TreeNode*root_r=root;
        while(root_l!=NULL)
        {
            lh++;
            root_l=root_l->left;
        }
        while(root_r!=NULL)
        {
            rh++;
            root_r=root_r->right;
        }
        if(lh==rh)
        {
            return (1<<rh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};