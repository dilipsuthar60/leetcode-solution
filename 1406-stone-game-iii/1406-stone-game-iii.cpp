class Solution {
public:
    int n;
    int dp[50005][2];
    int find(vector<int>&nums,int index,int turn)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index][turn]!=-1)
        {
            return dp[index][turn];
        }
        int ans=((turn)?-1e9:1e9);
        int sum=0;
        for(int i=index;i<min(n,index+3);i++)
        {
            sum+=nums[i];
            if(turn)
            {
                ans=max(ans,sum+find(nums,i+1,turn^1));
            }
            else
            {
                ans=min(ans,-sum+find(nums,i+1,turn^1));
            }
        }
        return dp[index][turn]= ans;
    }
    string stoneGameIII(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        int score=find(nums,0,1);
        if(score>0)
        {
            return "Alice";
        }
        else if(score<0)
        {
            return "Bob";
        }
        return "Tie";
    }
};