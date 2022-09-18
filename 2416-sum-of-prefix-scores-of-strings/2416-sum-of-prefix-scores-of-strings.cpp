class Solution {
public:
        struct node
    {
        node*child[26]={NULL};
        int count=0;
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
            curr->count++;
        }
    }
    int find(node*curr,string &s)
    {
        int ans=0;
        for(char &ch:s)
        {
            if(curr->child[ch-'a']!=NULL)
            {
                curr=curr->child[ch-'a'];
                ans+=curr->count;
            }
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>&nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            insert(nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            node*curr=root;
            int value=find(curr,nums[i]);
            // cout<<endl;
            ans.push_back(value);
        }
        return ans;
    }
};