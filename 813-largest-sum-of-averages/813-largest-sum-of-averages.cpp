class Solution {
public:
    double dp[110][110];
    double find(vector<int>&nums,int index,int k)
    {
        if(index>=nums.size()||k<0)
        {
            return 0;
        }
        if(k==1)
        {
            double sum=0;
            int count=0;
            for(int i=index;i<nums.size();i++)
            {
                count++;
                sum+=nums[i];
            }
            return sum/count;
        }
        if(dp[index][k]!=0)
        {
            return dp[index][k];
        }
        double sum=0;
        double ans=0;
        for(int i=index;i<nums.size();i++)
        {
            sum+=nums[i];
            ans=max(ans,sum/(i-index+1)+find(nums,i+1,k-1));
        }
        return dp[index][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        memset(dp,0,sizeof(dp));
        return find(nums,0,k);
    }
};