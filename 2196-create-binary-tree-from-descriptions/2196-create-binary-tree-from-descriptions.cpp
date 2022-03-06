
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& nums) 
    {
        unordered_map<int,TreeNode*>mp;
        set<int>s;
        for(auto &it:nums)
        {
            if(mp.find(it[0])==mp.end())
            {
                TreeNode*new_node=new TreeNode(it[0]);
                mp[it[0]]=new_node;
            }
             if(mp.find(it[1])==mp.end())
            {
                TreeNode*new_node=new TreeNode(it[1]);
                mp[it[1]]=new_node;
            }
            if(it[2]==1)
            {
                mp[it[0]]->left=mp[it[1]];
            }
            if(it[2]==0)
            {
                 mp[it[0]]->right=mp[it[1]];
            }
            s.insert(it[1]);
        }
        for(auto it:nums)
        {
            if(s.count(it[0])==0)
            {
                return mp[it[0]];
            }
        }
        return nullptr;
    }
};