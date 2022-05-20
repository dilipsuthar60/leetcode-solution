class Solution {
public:
    struct node
    {
        node*child[2]={NULL};
        int val=-1;
    };
    node*root=new node();
    void insert(int n)
    {
        node*curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit=((1<<i)&n)>0?1:0;
            if(curr->child[bit]==NULL)
            {
                curr->child[bit]=new node();
            }
            curr=curr->child[bit];
        }
        curr->val=n;
    }
    int max_xor(int n)
    {
         int ans=0;
        node*curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit=((1<<i)&n)>0?1:0;
            if(curr->child[!bit]!=NULL)
            {
                ans|=(1<<i);
                curr=curr->child[!bit];
            }
            else
            {
                curr=curr->child[bit];
            }
        }
        return ans;
       
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) 
    {
        int n=nums.size();
        for(int i=0;i<q.size();i++)
        {
            q[i].push_back(i);
        }
        int m=0;
        int j=0;
        vector<int>ans(q.size(),-1);
        sort(nums.begin(),nums.end());
        sort(q.begin(),q.end(),[&](auto &a,auto &b)
             {
                 return a[1]<b[1];
             });
        for(int i=0;i<q.size();i++)
        {
            int val=q[i][0];
            int range=q[i][1];
            int index=q[i][2];
            while(j<n&&nums[j]<=range)
            {
                insert(nums[j]);
                j++;
            }
            if(j==0)
            {
                continue;
            }
            int value=max_xor(val);
            ans[index]=value;
        }
        return ans;
    }
};