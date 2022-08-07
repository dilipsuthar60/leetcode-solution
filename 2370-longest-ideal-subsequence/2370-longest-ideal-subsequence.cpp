class Solution {
public:
    int n;
    int dp[100005][27];
    int find(string&s,int index,char prev,int &k)
    {
        if(index>=n)
        {
            return 0;
        }
        int prev_index=0;
        if(prev=='#')
        {
            prev_index=26;
        }
        else
        {
            prev_index=int(prev-'a');
        }
        if(dp[index][prev_index]!=-1)
        {
            return dp[index][prev_index];
        }
        int ans=0;
        if(prev=='#'||abs(prev-s[index])<=k)
        {
            ans=max(ans,1+find(s,index+1,s[index],k));
        }
        ans=max(ans,find(s,index+1,prev,k));
        return dp[index][prev_index]= ans;
    }
    int longestIdealString(string s, int k) 
    {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        return find(s,0,'#',k);
    }
};