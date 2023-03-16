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
    int i;
    TreeNode*find(vector<int>&in,vector<int>&pos,int s,int e)
    {
        if(s>e)
            return NULL;
        TreeNode *root=new TreeNode(pos[i]);
        int index=-1;
        for(int j=s;j<=e;j++)
        {
            if(in[j]==pos[i])
            {
                index=j;
                break;
            }
        }
        i--;
         root->right=find(in,pos,index+1,e);
        root->left=find(in,pos,s,index-1);
        // root->right=find(in,pos,index+1,e);
        return root;    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n=inorder.size();
        i=n-1;
        TreeNode*root=find(inorder,postorder,0,n-1);
        return root;
    }
};