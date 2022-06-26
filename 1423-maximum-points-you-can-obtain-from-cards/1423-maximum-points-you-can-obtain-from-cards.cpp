class Solution {
public:
    int maxScore(vector<int>&nums, int k) 
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
            sum-=nums[k-1-i];
            sum+=nums[n-i-1];
            ans=max(ans,sum);
        }
        return ans;
    }
};