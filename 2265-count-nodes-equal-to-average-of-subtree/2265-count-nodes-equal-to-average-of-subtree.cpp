/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        pair<int, int> find(TreeNode *root, int &sum)
        {
            if (root == NULL)
            {
                return { 0,
                    0 };
            }
            auto p1 = find(root->left, sum);
            auto p2 = find(root->right, sum);
            if (((p1.first + p2.first + root->val) / (p1.second + p2.second + 1)) == root->val)
            {
                sum++;
            };
            return {p1.first + p2.first + root->val,p1.second + p2.second + 1};
        }
    int averageOfSubtree(TreeNode *root)
    {
        int sum = 0;
        find(root, sum);
        return sum;
    }
};