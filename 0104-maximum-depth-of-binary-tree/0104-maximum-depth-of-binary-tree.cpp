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
    void find(TreeNode*root,int level)
    {
        if(root==NULL)
        {
            return ;
        }
        ans=max(ans,level+1);
        find(root->left,level+1);
        find(root->right,level+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        ans=0;
        find(root,0);
        return ans;
    }
};