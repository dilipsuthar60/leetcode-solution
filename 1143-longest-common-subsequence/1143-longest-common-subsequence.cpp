class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int find(string &s1,string &s2,int index1,int index2)
    {
        if(index1==n||index2==m)
        {
            return 0;
        }
        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }
        if(s1[index1]==s2[index2])
        {
            return dp[index1][index2]=1+find(s1,s2,index1+1,index2+1);
        }
        return dp[index1][index2]= max(find(s1,s2,index1+1,index2),find(s1,s2,index1,index2+1));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        memset(dp,-1,sizeof(dp));
        n=text1.size();
        m=text2.size();
        return find(text1,text2,0,0);
    }
};