class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long prod=1;
        int count=0;
        for(int i=0,j=0,n=nums.size();i<n;i++)
        {
            prod*=nums[i];
            while(prod>=k&&j<=i)
            {
                prod/=nums[j++];
            }
            count+=(i-j+1);
        }
        return count;
    }
};