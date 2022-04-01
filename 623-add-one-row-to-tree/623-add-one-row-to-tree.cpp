class Solution {
public:
    void find(TreeNode*root,int v,int d,int level)
    {
        if(root==NULL)
        {
            return ;
        }
        if(d-1==level)
        {
            TreeNode*node1=new TreeNode(v);
            TreeNode*node2=new TreeNode(v);
            node1->left=root->left;
            root->left=node1;
            node2->right=root->right;
            root->right=node2;
            return ;
        }
        find(root->left,v,d,level+1);
        find(root->right,v,d,level+1);
        return ;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if(d==1)
        {
            TreeNode*node=new TreeNode(v);
            node->left=root;
            return node;
        }
         find(root,v,d,1);
        return root;
    }
};