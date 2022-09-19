class Solution {
public:
    struct node
    {
        node*child[26]={NULL};
        int end=0;
    };
    node*root=new node();
    void insert(string s)
    {
        int n=s.size();
        node*curr=root;
        for(int i=0;i<n;i++)
        {
            if(curr->child[s[i]-'a']==NULL)
            {
                curr->child[s[i]-'a']=new node();
            }
            curr=curr->child[s[i]-'a'];
        }
        curr->end=1;
    }
    bool find(node* root,node* curr,int index,string &s,int count)
    {
        if(!curr)
        {
            return false;
        }
        if(index>=s.size())
        {
            if(curr->end&&count>=1)
            {
                return true;
            }
            return false;
        }
        if(curr->end&&find(root,root,index,s,count+1))
        {
            return true;
        }
        return find(root,curr->child[s[index]-'a'],index+1,s,count);
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& nums) 
    {
        vector<string>ans;
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a.size()<b.size();});
        for(auto &s:nums)
        {
            if(find(root,root,0,s,0))
            {
                ans.push_back(s);
            }
            else
            {
                insert(s);
            }
        }
        return ans;
    }
};