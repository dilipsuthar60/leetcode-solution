class Solution {
public:
    long long dp[1001][1001];
    vector<vector<int>>mp;
    int n;
    const int mod=1e9+7;
    int find(string &s,int i,int j)
    {
        if(i>=n||j>=s.size())
        {
            return j==s.size();
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j]%mod;
        }
        int ch=s[j]-'a';
        long long ans=0;
        ans=find(s,i+1,j);
        ans+=1ll*mp[ch][i]*find(s,i+1,j+1);
        return dp[i][j]=ans%mod;
    }
    int numWays(vector<string>&nums, string target) 
    {
        n=nums[0].size();
        mp=vector<vector<int>>(26,vector<int>(n,0));
        for(auto it:nums)
        {
            for(int i=0;i<it.size();i++)
            {
                mp[it[i]-'a'][i]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return find(target,0,0)%mod;
    }
};