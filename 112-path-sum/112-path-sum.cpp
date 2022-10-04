class Solution {
public:
    bool find(TreeNode*root,int sum)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            return sum-root->val==0;
        }
        if(find(root->left,sum-root->val)||find(root->right,sum-root->val))
        {
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return find(root,targetSum);
    }
};