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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode*,unsigned long long int>>q;
        q.push({root,0});
        unsigned long long int ans=0;
        while(!q.empty())
        {
            unsigned long long int left=0,right=0;
            unsigned long long int n=q.size();
            left=q.front().second;
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                right=it.second;
                if(it.first->left!=NULL)
                {
                    q.push({it.first->left,2*it.second+1});
                }
                if(it.first->right!=NULL)
                {
                    q.push({it.first->right,2*it.second+2});
                }
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};