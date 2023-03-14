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
    int sumNumbers(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                TreeNode*node=temp.first;
                int sum=temp.second;
                if(node->left==NULL&&node->right==NULL)
                {
                    ans=ans+sum;
                }
                if(node->left!=NULL)
                {
                    q.push({node->left,sum*10+node->left->val});
                }
                if(node->right!=NULL)
                {
                     q.push({node->right,sum*10+node->right->val});
                }
            }
        }
        return ans;
    }
};