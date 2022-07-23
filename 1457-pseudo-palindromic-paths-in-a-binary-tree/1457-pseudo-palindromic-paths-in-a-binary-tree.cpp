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
    void find(TreeNode*root,int count)
    {
        if(root==NULL)
        {
            return ;
        }
        count^=(1<<(root->val));
        if(root->left==NULL&&root->right==NULL)
        {
            ans+=((count&(count-1))==0);
        }
        find(root->left,count);
        find(root->right,count);
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        find(root,0);
        return ans;
    }
};