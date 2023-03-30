class Solution {
public:
    long long n,goal,k;
    int mod=1e9+7;
    long long dp[111][111];
    long long find(int index,int unique)
    {
        if(index>=goal)
        {
            return unique==n;
        }
        if(dp[index][unique]!=-1)
        {
            return dp[index][unique];
        }
        long long ans=0;
        if(unique>k)
        {
            ans+=find(index+1,unique)*(unique-k);
        }
        ans+=find(index+1,unique+1)*(n-unique);
        return dp[index][unique]=ans%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) 
    {
        memset(dp,-1,sizeof(dp));
        this->n=n;
        this->goal=goal;
        this->k=k;
        return find(0,0)%mod;
    }
};