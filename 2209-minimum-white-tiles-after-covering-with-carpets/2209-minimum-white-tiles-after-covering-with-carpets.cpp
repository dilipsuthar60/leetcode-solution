class Solution {
public:
    int n;
    int dp[1011][1011];
    int find(string &s,vector<int>&prefix,int index,int num,int len)
    {
        if(index>=n)
        {
            return 0;
        }
        if(num==0)
        {
            return 0;
        }
        if(dp[index][num]!=-1)
        {
            return dp[index][num];
        }
        int one=prefix[min(n-1,index+len-1)]-(index?prefix[index-1]:0);
        int take=one+find(s,prefix,index+len,num-1,len);
        int not_take=find(s,prefix,index+1,num,len);
        return dp[index][num]=max(take,not_take);
    }
    int minimumWhiteTiles(string s, int num, int len) 
    {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        vector<int>prefix(n);
        int c=0;
        for(int i=0;i<n;i++)
        {
            prefix[i]=(s[i]=='1')?1:0;
            if(i)
            {
                prefix[i]+=prefix[i-1];
            }
        }
        int val=find(s,prefix,0,num,len);
        return prefix[n-1]-val;
    }
};