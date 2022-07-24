class Solution {
public:
    int numberOfUniqueGoodSubsequences(string s) 
    {
        int n=s.size();
        long long zero=0;
        long long end1=0;
        long long end0=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                zero=1;
                end0=(end0+end1)%mod;
            }
            else
            {
                end1=(end1+end0+1)%mod;
            }
        }
        return (zero+end1+end0)%mod;
    }
};