class Solution {
public:
    int maxScore(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        int ans=sum;
        for(int i=0;i<k;i++)
        {
            sum=sum-nums[k-1-i];
            sum=sum+nums[n-1-i];
            ans=max(ans,sum);
        }
        return ans;
    }
};