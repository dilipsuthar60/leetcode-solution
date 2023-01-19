class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    bool find(string &s,string&p,int i,int j)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==s.size()&&j==p.size())
        {
            return dp[i][j]= true;
        }
        else if(i==s.size())
        {
            for(int k=j;k<p.size();k++)
            {
                if(p[k]!='*')
                {
                    return dp[i][j]=false;
                }
            }
            return dp[i][j] = true;
        }
        else if(j==p.size())
        {
            return dp[i][j]=false;
        }
        if((s[i]==p[j]||p[j]=='?')&&find(s,p,i+1,j+1))
        {
            return dp[i][j]=true;
        }
        else if(p[j]=='*'&&(find(s,p,i,j+1)||find(s,p,i+1,j)))
        {
            return dp[i][j]=true;
        }
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) 
    {
        n=s.size();
        m=p.size();
        dp=vector<vector<int>>(n+10,vector<int>(m+10,-1));
        return find(s,p,0,0);
    }
};