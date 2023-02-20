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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if(root==NULL)
            return {};
        vector<vector<int>>v;
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            vector<int>res;
            int size=q.size();
            count++;
            for(int i=0;i<size;i++)
            {

                TreeNode *temp=q.front();
                q.pop();
                res.push_back(temp->val);
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            v.push_back(res);
        }
        for(int i=0;i<v.size();i++)
        {
            if(i%2!=0)
            {
                reverse(v[i].begin(),v[i].end());
            }
        }
        return v;
    }
};