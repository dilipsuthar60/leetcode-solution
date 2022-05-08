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
    class node
    {
        public:
        int sum;
        int size;
        node(int sum,int size)
        {
            this->sum=sum;
            this->size=size;
        }
    };
    node find(TreeNode*root,int&count)
    {
        if(root==NULL)
        {
            //first sum of subtree
            // second size of subtree
            return node(0,0);
        }
        auto left=find(root->left,count);
        auto right=find(root->right,count);
        int sum_of_subtree=root->val+left.sum+right.sum;
        int size_of_subtree=1+left.size+right.size;
        if((sum_of_subtree)/(size_of_subtree)==root->val)
        {
            count++;
        }
        node new_node(sum_of_subtree,size_of_subtree);
        return new_node;
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int sum=0;
        find(root,sum);
        return sum;
    }
};