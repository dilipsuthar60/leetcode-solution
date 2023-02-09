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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string>ans;
        queue<pair<TreeNode*,string>>q;
        q.push({root,to_string(root->val)});
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            TreeNode*node=temp.first;
            string path=temp.second;
            if(node->left==NULL&&node->right==NULL)
            {
                ans.push_back(path);
                continue;
            }
            if(node->left!=NULL)
            {
                q.push({node->left,path+"->"+to_string(node->left->val)});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,path+"->"+to_string(node->right->val)});
            }
        }
        return ans;
    }
};