/**
 vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int>m;
        vector<TreeNode*>res;
        DFS(root, m, res);
        return res;
    }
    
    string DFS(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& res){
        if(!root) return "";
        string s = to_string(root->val) + "," + DFS(root->left, m, res) + "," + DFS(root->right, m, res);
        if(m[s]++ == 1) res.push_back(root);
        return s;
    }
 */
class Solution {
public:
    string find(TreeNode*root,unordered_map<string,int>&mp,vector<TreeNode*>&v)
    {
        if(root==NULL)
        {
            return "";
        }
        string s=to_string(root->val)+","+find(root->left,mp,v)+","+find(root->right,mp,v);
        cout<<s<<" ";
        mp[s]++;
        if(mp[s]==2)
        {
            v.push_back(root);
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map<string,int>mp;
        vector<TreeNode*>v;
        find(root,mp,v);
        return v;
    }
};