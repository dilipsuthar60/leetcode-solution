// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
long long int longestCommon (long long int n1, long long int n2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long int n1, n2; cin >> n1 >> n2;

        cout << longestCommon (n1, n2) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

vector<vector<int>>dp;
string s1,s2;
string bin(long long n)
{
    string s="";
    while(n)
    {
        if(n&1)
        {
            s.push_back('1');
        }
        else
        {
            s.push_back('0');
        }
        n=n/2;
    }
    reverse(s.begin(),s.end());
    return s;
}
long long cal(int start,int end)
{
    string str="";
    while(dp[start][end]!=0)
    {
        str.push_back(s1[start-1]);
        start--;
        end--;
    }
    // cout<<start<<" "<<end<<"  "<<str<<endl;
    long long int ans=0;
    for(int i=str.size()-1;~i;i--)
    {
        ans=ans<<1|(str[i]-'0');
    }
    return ans;
}
long long int longestCommon (long long int N, long long int M)
{
    s1=bin(N);
    s2=bin(M);
    int n=s1.size();
    int m=s2.size();
    dp=vector<vector<int>>(n+1,vector<int>(m+1,0));
    int len=0;
    int start=0;
    int end=0;
    long long int org=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                if(dp[i][j]>len)
                {
                    len=dp[i][j];
                }
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    vector<pair<int,int>>v;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dp[i][j]==len)
            {
                v.push_back({i,j});
            }
        }
    }
    for(auto it:v)
    {
        org=max(org,cal(it.first,it.second));
    }
    return org;
}