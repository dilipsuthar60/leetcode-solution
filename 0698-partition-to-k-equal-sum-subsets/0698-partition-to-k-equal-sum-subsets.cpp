class Solution {
public:
    int dp[(1<<16)+100];
    bool find(vector<int>&nums,int target,int k,int mask,int count,int sum)
    {
        if(k-1==(count))
        {
            return true;
        }
        if(dp[mask]!=-1)
        {
            return dp[mask];
        }
        for(int i=0;i<nums.size();i++)
        {
            if((mask&(1<<i))==0)
            {
                if(sum+nums[i]>target)
                {
                    break;
                }
                if(sum+nums[i]==target)
                {
                    mask^=(1<<i);
                    if(find(nums,target,k,mask,count+1,0))
                    {
                        return true;
                    }
                    mask^=(1<<i);
                }
                else
                {
                    mask^=(1<<i);
                    if(find(nums,target,k,mask,count,sum+nums[i]))
                    {
                        return true;
                    }
                    mask^=(1<<i);
                }
            }
        }
        return dp[mask] =false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k)
        {
            return false;
        }
        return find(nums,sum/k,k,0,0,0);
    }
};