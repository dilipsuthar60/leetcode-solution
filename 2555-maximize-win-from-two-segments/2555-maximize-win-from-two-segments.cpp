class Solution {
public:
    long long range=0;
    long long n;
    long long dp[100500][3];
    int find(vector<int>&nums,int index,int count)
    {
        if(count==0||index>=n)
        {
            return 0;
        }
        if(dp[index][count]!=-1)
        {
            return dp[index][count];
        }
        long long ans=find(nums,index+1,count);
        long long it=upper_bound(nums.begin(),nums.end(),nums[index]+range)-nums.begin();
        ans=max(ans,it-index+find(nums,it,count-1));
        return dp[index][count]= ans;
    }
    int maximizeWin(vector<int>& prizePositions, int k) 
    {
        memset(dp,-1,sizeof(dp));
        n=prizePositions.size();
        range=k;
        return find(prizePositions,0,2);
    }
};