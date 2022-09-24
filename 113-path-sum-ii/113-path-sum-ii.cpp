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
    void find(TreeNode*root,int sum,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(root==NULL)
        {
            return ;
        }
        sum-=root->val;
        if(root->left==NULL&&root->right==NULL)
        {
            curr.push_back(root->val);
            if(sum==0)
            {
                ans.push_back(curr);
            }
            curr.pop_back();
            return ;
        }
        curr.push_back(root->val);
        find(root->left,sum,curr,ans);
        curr.pop_back();
        curr.push_back(root->val);
        find(root->right,sum,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        find(root,targetSum,curr,ans);
        return ans;
    }
};