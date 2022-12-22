class Solution {
public:
    int n;
    int dp[1001][1001];
    vector<int>prefix;
    int sum(int l,int r)
    {
        return prefix[r+1]-prefix[l];
    }
    int find(vector<int>&nums,int left,int right,int A)
    {
        if(left>=right)
        {
            return 0;
        }
        if(dp[left][right]!=-1)
        {
            return dp[left][right];
        }
        int cost=0;
        if(A)
        {
            int first=sum(left+1,right)+find(nums,left+1,right,A^1);
            int second=sum(left,right-1)+find(nums,left,right-1,A^1);
            cost=max(first,second);
        }
        else
        {
            int first=-sum(left+1,right)+find(nums,left+1,right,A^1);
            int second=-sum(left,right-1)+find(nums,left,right-1,A^1);
            cost= min(first,second);
        }
        return dp[left][right] = cost;
    }
    int stoneGameVII(vector<int>& nums) 
    {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        prefix=vector<int>(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        return find(nums,0,n-1,1);
    }
};