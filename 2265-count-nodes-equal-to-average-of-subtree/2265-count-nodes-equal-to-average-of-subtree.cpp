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
    pair<int,int>find(TreeNode*root,int&sum)
    {
        if(root==NULL)
        {
            //first sum of subtree
            // second size of subtree
            return {0,0};
        }
        auto left=find(root->left,sum);
        auto right=find(root->right,sum);
        int sum_of_subtree=root->val+left.first+right.first;
        int size_of_subtree=1+left.second+right.second;
        if((sum_of_subtree)/(size_of_subtree)==root->val)
        {
            sum++;
        }
        return {sum_of_subtree,size_of_subtree};
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int sum=0;
        find(root,sum);
        return sum;
    }
};