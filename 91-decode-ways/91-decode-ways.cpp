class Solution {
public:
    int dp[110];
    int find(string &s,int index)
   {
        if(index==s.size())
        {
            return 1;
        }
        if(s[index]=='0')
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int ans=find(s,index+1);
        if(index+1<s.size()&&stoi(s.substr(index,2))>=10&&stoi(s.substr(index,2))<=26)
        {
            ans+=find(s,index+2);
        }
        return dp[index]=ans;
    }
    int numDecodings(string s) 
    {
        memset(dp,-1,sizeof(dp));
        return find(s,0);
//         if(s.size()==1&&s[0]=='0')
//         {
//             return 0;
//         }

//          int n=s.size();
//         vector<int>dp(n+1,0);
//         dp[0]=(s[0]=='0'?0:1);
//         dp[1]=(s[1]=='0'?0:1);
//         for(int i=2;i<=n;i++)
//         {
//             int first=stoi(s.substr(i-1,1));
//             int second=stoi(s.substr(i-2,2));
//             if(first>=1&&first<=9)
//             {
//                 dp[i]+=dp[i-1];
//             }
//             if(second>=10&&second<=26)
//             {
//                 dp[i]+=dp[i-2];
//             }
//         }
        
//         return dp[0]==0?0:dp[n];
    }
};