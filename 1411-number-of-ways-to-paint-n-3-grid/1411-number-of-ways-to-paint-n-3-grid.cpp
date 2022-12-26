class Solution {
public:
    int mod=1e9+7;
    long long dp[5001][4][4][4];
    vector<vector<int>>result;
    void allColor(vector<int>&nums,int index,vector<int>curr)
    {
        if(index==3)
        {
            result.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(curr.size()==0||curr.back()!=nums[i])
            {
                curr.push_back(nums[i]);
                allColor(nums,index+1,curr);
                curr.pop_back();
            }
        }
    }
    long long find(int &n,int index,int a,int b,int c)
    {
        if(n==index)
        {
            return 1;
        }
        if(dp[index][a][b][c]!=-1)
        {
            return dp[index][a][b][c]%mod;
        }
        long long ans=0;
        for(auto &t:result)
        {
            if(t[0]!=a&&t[1]!=b&&t[2]!=c)
            {
                ans+=find(n,index+1,t[0],t[1],t[2]);
            }
        }
        return dp[index][a][b][c] = ans%mod;
    }
    int numOfWays(int n) {
        vector<int>nums={1,2,3};
        vector<int>curr;
        allColor(nums,0,curr);
        memset(dp,-1,sizeof(dp));
        return find(n,0,0,0,0)%mod;
    }
};