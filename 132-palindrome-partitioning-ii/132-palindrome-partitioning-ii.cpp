class Solution {
public:
    int dp2[2010];
    vector<vector<int>>find1(string&s)
    {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;j++,i++)
            {
                if(gap==0)
                {
                    dp[i][j]=1;
                }
                else if(gap==1)
                {
                    dp[i][j]=(s[i]==s[j]);
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
            }
        }
        return dp;
    }
    int find(string &s,int index,vector<vector<int>>&dp)
    {
        if(index>=s.size())
        {
            return 0;
        }
        if(dp[index][s.size()-1])
            return 0;
        if(dp2[index]!=-1)
        {
            return dp2[index];
        }
        int ans=INT_MAX;
        for(int i=index;i<s.size();i++)
        {
            if(dp[index][i])
            {
                ans=min(ans,1+find(s,i+1,dp));
            }
        }
        return dp2[index]=ans;
    }
    int minCut(string s) 
    {
        auto dp=find1(s);
        memset(dp2,-1,sizeof(dp2));
        int n=s.size();
        vector<int>min_pal(n,0);
       // return find(s,0,dp);
        min_pal[0]=0;
        for(int i=1;i<n;i++)
        {
            if(dp[0][i])
            {
                min_pal[i]=0;
            }
            else
            {
                min_pal[i]=INT_MAX;
                for(int j=i;j>0;j--)
                {
                    if(dp[j][i])
                    {
                        min_pal[i]=min(min_pal[i],1+min_pal[j-1]);
                    }
                }
            }
        }
        return min_pal[n-1];
    }
};