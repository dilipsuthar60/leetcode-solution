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
    unordered_map<int,int>mp;
    void find1(TreeNode*root,int d)
    {
        if(!root)return ;
        mp[d]+=root->val;
        find1(root->left,d+1);
        find1(root->right,d+1);
    }
    void find(TreeNode*root)
    {
        queue<TreeNode*>q;
        q.push(root);
        root->val=0;
        int level=0;
        while(q.size())
        {
            for(int i=q.size()-1;i>=0;i--)
            {
                auto temp=q.front();
                q.pop();
                int sum=mp[level+1];
                if(temp->left)
                {
                    sum-=temp->left->val;
                }
                if(temp->right)
                {
                    sum-=temp->right->val;
                }
                if(temp->left)
                {
                    temp->left->val=sum;
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    temp->right->val=sum;
                }
            }
            level++;
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        find1(root,0);
        find(root);
        return root;
    }
};