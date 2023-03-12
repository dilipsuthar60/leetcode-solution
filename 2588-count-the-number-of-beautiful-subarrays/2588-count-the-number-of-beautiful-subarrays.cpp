class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long count=0;
        unordered_map<int,long long>mp;
        mp[0]=1;
        for(int i=0,sum=0,n=nums.size();i<n;i++)
        {
            sum^=nums[i];
            count+=mp[sum];
            mp[sum]++;
        }
        return count;
    }
};