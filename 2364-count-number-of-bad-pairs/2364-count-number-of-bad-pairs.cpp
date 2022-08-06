class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long ,long long>mp;
        int n=nums.size();
        long long count=1ll*n*(n-1)/2;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]-i)!=mp.end())
            {
                count-=1ll*mp[nums[i]-i];
            }
            mp[nums[i]-i]++;
        }
        return count;
    }
};