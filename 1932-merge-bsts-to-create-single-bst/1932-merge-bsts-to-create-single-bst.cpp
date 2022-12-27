class Solution 
{
public:
    bool check_bst(TreeNode*root,int l=-1e9,int r=1e9)
    {
        if(root==NULL)
        {
            return true;
        }
        if(!(root->val>l&&root->val<r))
        {
            return false;
        }
        return check_bst(root->left,l,root->val)&&check_bst(root->right,root->val,r);
    }
    void find(TreeNode*&root,unordered_map<int,TreeNode*>&mp)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left)
        {
            if(mp[root->left->val])
            {
                root->left=mp[root->left->val];
                mp[root->left->val]=NULL;
            }
        }
        if(root->right)
        {
            if(mp[root->right->val])
            {
                root->right=mp[root->right->val];
                mp[root->right->val]=NULL;
            }
        }
        find(root->left,mp);
        find(root->right,mp);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) 
    {
        unordered_map<int,int>mp;
        for(auto &it:trees)
        {
            mp[it->val]++;
            if(it->left!=NULL)
            {
                mp[it->left->val]++;
            }
            if(it->right!=NULL)
            {
                mp[it->right->val]++;
            }
        }
        TreeNode*root=NULL;
        for(auto &it:trees)
        {
            if(mp[it->val]==1)
            {
                if(root==NULL)
                {
                    root=it;
                }
                else
                {
                    return NULL;
                }
            }
        }
        unordered_map<int,TreeNode*>node;
        for(auto &it:trees)
        {
            node[it->val]=it;
        }
        find(root,node);
        int count=0;
        for(auto &it:node)
        {
            if(it.second!=NULL)
            {
                count++;
            }
        }
        if((!check_bst(root))||count>1)
        {
            return NULL;
        }
        return root;
    }
};