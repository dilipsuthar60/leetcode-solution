class Solution {
public:
    int mod=1e9+7;
    long long find(long long a,long long b)
    {
        long long res=1;
        while(b)
        {
            if(b&1)
            {
                res=(res*a)%mod;
            }
            a=(a*a)%mod;
            b=b/2;
        }
        return res%mod;
    }
    int monkeyMove(int n) {
        long long val=(find(2,n)-2+mod)%mod;
        return val;
    }
};