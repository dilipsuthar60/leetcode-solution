class Solution {
public:
    vector<int>dp[100005];
    void find(int node,vector<int>&sub,int p=-1)
    {
        for(auto &it:dp[node])
        {
            if(it!=p)
            {
                find(it,sub,node);
                sub[node]+=sub[it];
            }
        }
    }
    long long minimumFuelCost(vector<vector<int>>&nums, int seats) 
    {
        for(auto &it:nums)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        int n=nums.size();
        vector<int>sub(n+1,1);
        find(0,sub);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=(sub[i]+seats-1)/seats;
        }
        return ans;
    }
};