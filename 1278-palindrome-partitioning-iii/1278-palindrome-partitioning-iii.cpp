class Solution {
public:
    int n;
    int cost[101][101];
    int dp[101][101];
    int find(string &s,int index,int k)
    {
        if(k<0)
        {
            return 1e9;
        }
        if(index>=n)
        {
            if(k==0)
            {
                return 0;
            }
            return 1e9;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        int ans=1e9;
        for(int i=index;i<n;i++)
        {
            ans=min(ans,cost[index][i]+find(s,i+1,k-1));
        }
        return dp[index][k]= ans;
    }
    int palindromePartition(string s, int k) 
    {
        n=s.size();
        memset(cost,0,sizeof(cost));
        memset(dp,-1,sizeof(dp));
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;j++,i++)
            {
                if(gap==0)
                {
                    cost[i][j]=0;
                }
                else if(gap==1)
                {
                    cost[i][j]=!(s[i]==s[j]);
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        cost[i][j]=(cost[i+1][j-1]);
                    }
                    else
                    {
                        cost[i][j]=1+cost[i+1][j-1];
                    }
                }
            }
        }
        return find(s,0,k);
    }
};