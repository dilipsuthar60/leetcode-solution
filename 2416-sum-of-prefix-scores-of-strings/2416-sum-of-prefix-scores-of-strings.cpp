class Solution {
public:
        struct node
    {
        node*child[26]={NULL};
        int end=0;
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
        curr->end=1;
    }
    void find(node*curr,string &s,int &ans)
    {
        for(char &ch:s)
        {
            if(curr->child[ch-'a']!=NULL)
            {
                curr=curr->child[ch-'a'];
                // cout<<curr->count<<" ";
                ans+=curr->count;
            }
        }
        // cout<<endl;
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
            int count=0;
            find(curr,nums[i],count);
            // cout<<endl;
            ans.push_back(count);
        }
        return ans;
    }
};