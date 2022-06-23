class Solution {
public:
    int bestTeamScore(vector<int>& nums, vector<int>&age) 
    {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({age[i],nums[i]});
        }
        sort(v.begin(),v.end());
        auto find=[&]()
        {
            vector<int>dp(n,0);
            for(int i=0;i<n;i++)
            {
                dp[i]=v[i].second;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(v[i].second>=v[j].second &&dp[i]<dp[j]+v[i].second)
                    {
                        dp[i]=dp[j]+v[i].second;
                    }
                }
            }
            return *max_element(dp.begin(),dp.end());
        };
        return find();
    }
};