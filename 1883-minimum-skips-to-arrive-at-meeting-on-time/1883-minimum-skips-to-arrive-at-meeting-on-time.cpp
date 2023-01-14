class Solution {
public:
    long long n;
    long long speed;
    long long dp[1100][1100];
    long long find(vector<int>&nums,int index,int k)
    {
          if(k<0)
        {
            return 1e9;
        }
        if(index<0)
        {
            return 0;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        long long skip=1ll*nums[index]+find(nums,index-1,k-1);
        long long not_skip=((1ll*nums[index]+speed-1+find(nums,index-1,k))/speed)*speed;
        return dp[index][k]= min(skip,not_skip);
    }
    int minSkips(vector<int>&nums, int s, int hoursBefore) 
    {
        memset(dp,-1,sizeof(dp));
        speed=s;
        n=nums.size();
        long long total=1ll*hoursBefore*speed-nums.back();
        for(int i=0;i<n;i++)
        {
            long long val=find(nums,n-2,i);
            if(val<=total)
            {
                return i;
            }
        }
        return -1;
    }
};
