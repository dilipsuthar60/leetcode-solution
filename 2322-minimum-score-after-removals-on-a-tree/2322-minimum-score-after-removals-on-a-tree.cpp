class Solution {
public:
    vector<int>nums;
    unordered_set<int>dp[1001];
    int ans=1e9;
    int find(int x,int p)
    {
        int ans=nums[x];
        for(auto &it:dp[x])
        {
            if(it!=p)
            {
                ans^=find(it,x);
            }
        }
        return ans;
    }
    int find2(int x,int p,int &comp1,int &comp2)
    {
        int curr=nums[x];
        for(auto &it:dp[x])
        {
            if(it!=p)
            {
                int val=find2(it,x,comp1,comp2);
                ans=min(ans,max({val,comp1^val,comp2})-min({val,comp1^val,comp2}));
                curr^=val;
            }
        }
        return curr;
    }
    int minimumScore(vector<int>&v, vector<vector<int>>& edges) 
    {
        nums=v;
        for(auto &it:edges)
        {
            dp[it[0]].insert(it[1]);
            dp[it[1]].insert(it[0]);
        }
        for(auto &it:edges)
        {
            dp[it[0]].erase(it[1]);
            dp[it[1]].erase(it[0]);
            int sum1=find(it[0],-1);
            int sum2=find(it[1],-1);
            find2(it[0],-1,sum1,sum2);
            find2(it[1],-1,sum2,sum1);
            dp[it[0]].insert(it[1]);
            dp[it[1]].insert(it[0]);
        }
        return ans;
    }
};