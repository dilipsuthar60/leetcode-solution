class Solution {
public:
    class Node
    {
        public:
        TreeNode* node;
        int sum;
        Node(TreeNode* node,int sum)
        {
            this->node=node;
            this->sum=sum;
        }
    };
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return 0;
        }
        queue<Node>q;
        Node curr(root,root->val);
        q.push(curr);
        while(q.size())
        {
            Node curr=q.front();
            q.pop();
            if(curr.node->left==NULL&&curr.node->right==NULL)
            {
                if(curr.sum==targetSum)
                {
                    return true;
                }
            }
            if(curr.node->left)
            {
                q.push(Node(curr.node->left,curr.sum+curr.node->left->val));
            }
            if(curr.node->right)
            {
                q.push(Node(curr.node->right,curr.sum+curr.node->right->val));
            }
        }
        return false;
    }
};