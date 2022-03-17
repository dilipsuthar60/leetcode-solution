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
    TreeNode*lca(TreeNode*root,int x,int y)
    {
        if(root==NULL||root->val==x||root->val==y)
        {
            return root;
        }
        auto left=lca(root->left,x,y);
        auto right=lca(root->right,x,y);
        if(left!=NULL&&right!=NULL)
        {
            return root;
        }
        return left==NULL?right:left;
    }
    bool path(TreeNode*root,int val,string &s)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->val==val)
        {
            return true;
        }
        s.push_back('L');
        if(path(root->left,val,s))
            return true;
        s.pop_back();
        s.push_back('R');
        if(path(root->right,val,s))
            return true;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int start, int end)
    {
        string s="";
        TreeNode*comman=lca(root,start,end);
        string s1="",s2="";
        path(comman,start,s1);
        path(comman,end,s2);
        s1=string(s1.size(),'U');
        return s1+s2;;
    }
};