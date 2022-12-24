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
      // if(!root) return {INT_MAX, INT_MIN};
      //   auto [leftMin, leftMax]   = dfs(root -> left);
      //   auto [rightMin, rightMax] = dfs(root -> right);
      //   auto curMin = min({root -> val, leftMin, rightMin}), 
      // curMax = max({root -> val, leftMax, rightMax});        
      //   ans = max({ans, root -> val - curMin, curMax - root -> val});
      //   return {curMin, curMax};
    int ans;
    void find(TreeNode* root,vector<int>curr)
    {
        if(root==NULL)
        {
            return ;
        }
        curr.push_back(root->val);
        if(root->left==root->right)
        {
            sort(curr.begin(),curr.end());
            ans=max(ans,abs(curr.front()-curr.back()));
        }
        find(root->left,curr);
        find(root->right,curr);
        curr.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        ans=INT_MIN;
        vector<int>curr;
      
        find(root,curr);
     
        return ans;
    }
};