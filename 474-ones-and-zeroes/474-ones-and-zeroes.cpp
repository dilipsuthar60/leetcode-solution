class Solution {
public:
    int dp[605][101][101];
    int find(vector<string>&nums,int index,int m,int n)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index][m][n]!=-1)
        {
            return dp[index][m][n];
        }
        int count_one=count(nums[index].begin(),nums[index].end(),'1');
        int count_zero=nums[index].size()-count_one;
        int count=0;
        if(count_zero<=m&&count_one<=n)
        {
            count+=max(1+find(nums,index+1,m-count_zero,n-count_one),find(nums,index+1,m,n));
        }
        else
        {
            count+=find(nums,index+1,m,n);
        }
        return dp[index][m][n]=count;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return find(strs,0,m,n);
    }
};