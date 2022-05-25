class Solution
{
    public:
      
    int countVowelPermutation(int n)
    {
        int mod=1e9+7;
        long a,e,i,o,u;
        a=e=i=o=u=1;
        long aa,ee,ii,oo,uu;
        aa=ee=ii=oo=uu=0;
        for(int k=2;k<=n;k++)
        {
            aa=(e)%mod;
            ee=(a+i)%mod;
            ii=(a+e+o+u)%mod;
            oo=(i+u)%mod;
            uu=(a)%mod;
            a=aa;
            e=ee;
            i=ii;
            o=oo;
            u=uu;
        }
        return (a+e+i+o+u)%mod;
    }
};