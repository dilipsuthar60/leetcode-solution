class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) 
    {
        int n=req.size();
        unordered_map<string,int>mp;
        for(int i=0;i<req.size();i++)
        {
            mp[req[i]]=i;
        }
        vector<int>nums(people.size());
        for(int i=0;i<people.size();i++)
        {
            int mask=0;
            for(auto it:people[i])
            {
                mask|=(1<<mp[it]);
            }
            nums[i]=mask;
        }
        vector<int>dp(1<<n,INT_MAX/2);
        vector<vector<int>>ans(1<<n);
        dp[0]=0;
        ans[0]={};
        for(int mask=0;mask<(1<<n);mask++)
        {
            for(int i=0;i<nums.size();i++)
            {
                int new_mask=(mask|(nums[i]));
                if(dp[new_mask]>dp[mask]+1)
                {
                    ans[new_mask]=ans[mask];
                    ans[new_mask].push_back(i);
                    dp[new_mask]=dp[mask]+1;
                }
            }
        }
        return ans[(1<<n)-1];
    }
};