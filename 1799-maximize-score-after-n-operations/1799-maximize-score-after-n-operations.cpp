class Solution {
public:
    int n;
    int dp[10][1<<15];
    int find(vector<int>&nums,int ind,int mask)
    {
        if(ind>n/2)
        {
            return 0;
        }
        if(dp[ind][mask]!=-1)
        {
            return dp[ind][mask];
        }
        int val=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int m=(1<<i)+(1<<j);
                if((mask&m)==0)
                {
                    val=max(val,ind*(__gcd(nums[i],nums[j]))+find(nums,ind+1,mask|m));
                }
            }
        }
        return dp[ind][mask]=val;
    }
    int maxScore(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return find(nums,1,0);
    }
};