class Solution {
public:
    long long minimumRemoval(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=1e15;
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        for(int i=0;i<n;i++)
        {
            ans=min(ans,sum-1ll*(n-i)*nums[i]+0ll);
        }
        return ans;
    }
};