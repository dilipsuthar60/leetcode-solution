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
    int c=0;
    int find(TreeNode*root)
    {
        if(root==NULL)
        {
            return 1;
        }
        int left=find(root->left);
        int right=find(root->right);
        if(left==-1||right==-1)
        {
             c++;
            return 0;
        }
        if(left==0||right==0)
        {
         return 1;   
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) 
    {
        if(find(root)==-1)
        {
            c++;
        }
        return c;
    }
};