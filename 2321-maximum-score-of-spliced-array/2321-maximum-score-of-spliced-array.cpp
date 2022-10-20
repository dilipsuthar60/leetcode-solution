class Solution {
public:
    int find(vector<int>&nums)
    {
        int sum=0;
        int max_sum=0;
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            // sum=max(nums[i],nums[i]+sum);
            // max_sum=max(max_sum,sum);
        }
        return *max_element(dp.begin(),dp.end());
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) 
    {
        int sum1=accumulate(nums1.begin(),nums1.end(),0);
        int sum2=accumulate(nums2.begin(),nums2.end(),0);
        vector<int>first,second;
        for(int i=0;i<nums1.size();i++)
        {
            first.push_back(nums2[i]-nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            second.push_back(nums1[i]-nums2[i]);
        }
        return max({sum1+find(first),sum2+find(second)});
    }
};