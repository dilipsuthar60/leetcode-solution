class Solution {
public:
    int n;
    int dp[10][1<<15];
    int getHash(int x,int y)
    {
        return ((1<<x)+(1<<y));
    }
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
                int new_mask=getHash(i,j);
                if((mask&new_mask)==0)
                {
                    val=max(val,ind*(__gcd(nums[i],nums[j]))+find(nums,ind+1,mask|new_mask));
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