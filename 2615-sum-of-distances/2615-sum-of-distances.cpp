class Solution {
public:
    void find(vector<int>&nums,vector<long long>&ans)
    {
        long long right=accumulate(nums.begin(),nums.end(),0ll);
        long long left=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            right-=nums[i];
            ans[nums[i]]=(1ll*nums[i]*(i)-left)+(right-1ll*nums[i]*(n-i-1));
            left+=nums[i];
        }
    }
    vector<long long> distance(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<long long>ans(n,0);
        for(auto &[a,b]:mp)
        {
            find(b,ans);
        }
        return ans;
    }
};