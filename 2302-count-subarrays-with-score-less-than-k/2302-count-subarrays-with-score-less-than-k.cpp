class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int n=nums.size();
        long long count=0;
        int j=0;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while((1ll*sum*(i-j+1))>=k)
            {
                sum-=nums[j];
                j++;
            }
            count+=(i-j+1);
        }
        return count;
    }
};