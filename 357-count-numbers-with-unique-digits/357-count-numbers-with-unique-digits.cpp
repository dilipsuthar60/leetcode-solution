class Solution {
public:
    string s;
    int dp[2][10][1<<10][2];
    int find(int n,int tight=0,int pos=0,int mask=0,int reapt=0)
    {
        if(pos==n)
        {
            return reapt==1;
        }
        if(dp[tight][pos][mask][reapt]!=-1)
        {
            return dp[tight][pos][mask][reapt];
        }
        int ans=0;
        if(tight==1)
        {
            for(int i=0;i<=s[pos]-'0';i++)
            {
                int new_tight=0;
                if(i==s[pos]-'0')
                {
                    new_tight=1;
                }
                if(i==0&&mask==0)
                {
                    ans+=find(n,new_tight,pos+1,mask,reapt);
                }
                else if(mask&(1<<i))
                {
                    ans+=find(n,new_tight,pos+1,mask,1);
                }
                else
                {
                    ans+=find(n,new_tight,pos+1,mask|(1<<i),reapt);
                }
            }
        }
        else
        {
            for(int i=0;i<=9;i++)
            {
               if(i==0&&mask==0)
                {
                    ans+=find(n,0,pos+1,mask,reapt);
                }
                else if(mask&(1<<i))
                {
                    ans+=find(n,0,pos+1,mask,1);
                }
                else
                {
                    ans+=find(n,0,pos+1,mask|(1<<i),reapt);
                }
            }
        }
        return dp[tight][pos][mask][reapt]=ans;
    }
    int countNumbersWithUniqueDigits(int n)  
    {
        memset(dp,-1,sizeof(dp));
        s=to_string((int)pow(10,n)-1);
        return (int)pow(10,n)-find(s.size());
    }
};