class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)         
    {
        if(root==NULL)
        {
            return {};
        }
        stack<TreeNode*>s;
        s.push(root);
        vector<int>ans;
        while(s.size())
        {
            auto temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->right)
            {
                s.push(temp->right);
            }
            if(temp->left)
            {
                s.push(temp->left);
            }
        }
        return ans;
    }
};