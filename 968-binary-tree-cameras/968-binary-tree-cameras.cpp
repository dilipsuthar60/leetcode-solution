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
    int ans=0;
    string find(TreeNode*root)
    {
        if(root==NULL)
        {
            return "covered";
        }
        string left=find(root->left);
        string right=find(root->right);
        if(left=="need"||right=="need")
        {
            ans++;
            return "camera";
        }
        if(left=="camera"||right=="camera")
        {
            return "covered";
        }
        return "need";
    }
    int minCameraCover(TreeNode* root)
    {
        ans=0;
        if(find(root)=="need")
        {
            ans++;
        }
        return ans;
    }
};