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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        vector<long long>v;
        q.push(root);
        while(q.size())
        {
            int size=q.size();
            long long sum=0;
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                    
            }
            v.push_back(sum);
        }
        if(v.size()<k)
        {
            return -1;
        }
        sort(v.rbegin(),v.rend());
        return v[k-1];
    }
};