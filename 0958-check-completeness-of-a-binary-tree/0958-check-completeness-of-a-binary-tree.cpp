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
    int find(TreeNode*root)
    {
        if(root==NULL)
            return 0;
        int l=find(root->left);
        int r=find(root->right);
        return l+r+1;
    }
    bool check(TreeNode*root,int x,int level)
    {
        if(root==NULL)
        {
            return true;
        }
        if(level>=x)
        {
            return false;
        }
        return check(root->left,x,level*2+1)&&check(root->right,x,level*2+2);
    }
    bool isCompleteTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return true;
        }
        int count_node=find(root);
        bool x=check(root,count_node,0);
        return x==true;
    }
};