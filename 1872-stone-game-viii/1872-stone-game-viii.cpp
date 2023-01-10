class Solution {
public:
    int n;
    int dp[100010][2];
    int find(vector<int>&nums,int index,int turn)
    {
        if(index==nums.size()-1)
        {
            return turn?nums[index]:-nums[index];
        }
        if(dp[index][turn]!=-1)
        {
            return dp[index][turn];
        }
        if(turn)
        {
            int a=nums[index]+find(nums,index+1,turn^1);
            int b=find(nums,index+1,turn);
            return dp[index][turn]= max(a,b);
        }
        else
        {
            int a=-nums[index]+find(nums,index+1,turn^1);
            int b=find(nums,index+1,turn);
            return dp[index][turn] = min(a,b);
        }
    }
    int stoneGameVIII(vector<int>&nums) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        return find(nums,1,1);
    }
};