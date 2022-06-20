class Solution {
public:
    class node
    {
        public:
         node*child[26]={NULL};
    };
    node *root=new node();
    int insert(string s)
    {
        int exist=0;
        node*curr=root;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(curr->child[s[i]-'a']==NULL)
            {
                exist=1;
                curr->child[s[i]-'a']=new node();
            }
            curr=curr->child[s[i]-'a'];
        }
        return exist;
    }
    int minimumLengthEncoding(vector<string>&nums)
    {
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a.size()>b.size();});
        int count=0;
        for(auto it:nums)
        {
            if(insert(it))
            {
                count+=it.size()+1;
            }
        }
        return count;
    }
};