class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long count=0;
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            else
            {
                ans+=(count*(count+1)/2);
                count=0;
            }
        }
        return ans+1ll*(count*(count+1)/2);
    }
};