class Solution {
public:
    int n;
    int yes=0;
    bool is_ok(vector<int>&nums,int mask)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
                mp[nums[i]]++;
            }
        }
        for(auto &[a,b]:mp)
        {
            if(b>=2)
            {
                return false;
            }
        }
        return true;
    }
    int dp[17][(1<<17)+10];
    int find(vector<pair<int,int>>&nums,int index,int subset,int k)
    {
        if(index==k)
        {
            yes=1;
            return 0;
        }
        if(dp[index][subset]!=-1)
        {
            return dp[index][subset];
        }
        int ans=1e9;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i].first&subset)==0)
            {
                ans=min(ans,nums[i].second+find(nums,index+1,nums[i].first|subset,k));
            }
        }
        return dp[index][subset]=ans;
    }
    int minimumIncompatibility(vector<int>& nums, int k) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        int g=n/k;
        vector<pair<int,int>>ans;
        for(int i=0;i<(1<<n);i++)
        {
            int count=0;
            int min_val=INT_MAX;
            int max_val=INT_MIN;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    min_val=min(min_val,nums[j]);
                    max_val=max(max_val,nums[j]);
                    count++;
                }
            }
            if(count==g&&is_ok(nums,i))
            {
                ans.push_back({i,max_val-min_val});
            }
        }
        int val=find(ans,0,0,k);
        if(yes)
        {
            return val;
        }
        return -1;
    }
};