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
    void find(TreeNode*root,unordered_map<int,long long>&mp,int level=0)
    {
        if(root==NULL)
        {
            return ;
        }
        mp[level]+=root->val;
        find(root->left,mp,level+1);
        find(root->right,mp,level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        unordered_map<int,long long>mp;
        find(root,mp);
        vector<long long>v;
        for(auto it:mp){
            v.push_back(it.second);
        }
        if(v.size()<k)
        {
            return -1;
        }
        sort(v.begin(),v.end(),greater<long long>());
        return v[k-1];
    }
};