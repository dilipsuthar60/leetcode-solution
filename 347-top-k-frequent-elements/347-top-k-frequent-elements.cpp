class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {   
        int n=nums.size();
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++)
      {
        mp[nums[i]]++;
      }
        vector<vector<int>>dp(n+1);
        for(auto it:mp)
        {
            dp[it.second].push_back(it.first);
        }
        vector<int>ans(k);
        int index=0;
        for(int i=n;i>=0;i--)
        {
            if(dp[i].size()!=0)
            {
                for(auto it:dp[i])
                {
                    ans[index++]=it;
                    if(index==k)
                    {
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};