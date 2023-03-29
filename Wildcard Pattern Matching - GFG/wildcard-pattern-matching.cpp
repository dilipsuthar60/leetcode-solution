//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
  int dp[250][250];
/*You are required to complete this method*/
    int find(string &s,string &p,int i,int j)
    {
        if(i==s.size()&&j==p.size())
        {
            return dp[i][j]= 1;
        }
        if(i==s.size())
        {
            for(int k=j;k<p.size();k++)
            {
                if(p[k]!='*')
                {
                    return dp[i][j]=0;
                }
            }
            return dp[i][j]= 1;
        }
        if(j==p.size())
        {
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1)
        {
            return  dp[i][j];
        }
        if(s[i]==p[j]||(p[j]=='?'))
        {
            return dp[i][j]= find(s,p,i+1,j+1);
        }
        else if(p[j]=='*')
        {
            return dp[i][j]= find(s,p,i,j+1)||find(s,p,i+1,j);
        }
        return dp[i][j]= 0;
    }
    int wildCard(string p,string s)
    {
        memset(dp,-1,sizeof(dp));
        return find(s,p,0,0);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends