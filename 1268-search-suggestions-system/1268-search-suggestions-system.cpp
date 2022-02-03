class Solution
{
public:
    struct node
    {
        node*child[26]={NULL};
        int end=0;
    };
    node*root=new node();
    void insert(string &s)
    {
        int n=s.size();
        node*curr=root;
        for(int i=0;i<n;i++)
        {
            int index=s[i]-'a';
            if(curr->child[index]==NULL)
            {
                curr->child[index]=new node();
            }
            curr=curr->child[index];
        }
        curr->end=1;
    }
    void dfs(node*curr,string &s,vector<string>&res)
    {
        if(res.size()==3)
        {
            return ;
        }
        if(curr->end)
        {
            res.push_back(s);
            
        }
        for(char ch='a';ch<='z';ch++)
        {
            if(curr->child[ch-'a']!=NULL)
            {
                s.push_back(ch);
                dfs(curr->child[ch-'a'],s,res);
                s.pop_back();
            }
        }
    }
    void find(string prefix,vector<string>&res)
    {
        node*curr=root;
        for(int i=0;i<prefix.size();i++)
        {
            int index=prefix[i]-'a';
            if(curr->child[index]==NULL)
            {
                return ;
            }
            curr=curr->child[index];
        }
        dfs(curr,prefix,res);
    }
    vector<vector<string>> suggestedProducts(vector<string>&nums, string s)
    {
        int n=s.size();
        for(int i=0;i<nums.size();i++)
        {
            insert(nums[i]);
        }
        string prefix="";
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            prefix.push_back(s[i]);
            vector<string>res;
            find(prefix,res);
            ans.push_back(res);
        }
        return ans;
    }
};