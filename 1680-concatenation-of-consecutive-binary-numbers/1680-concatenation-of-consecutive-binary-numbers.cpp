class Solution {
public:
    const int m=1e9+7;
    int find(int n)
    {
        // int count=0;
        // while(n>0)
        // {
        //     count++;
        //     n=n/2;
        // }
        return log2(n)+1;
    }
    int concatenatedBinary(int n) 
    {
        long long ans=1;
        for(int i=2;i<=n;i++)
        {
            int bit=find(i);
            ans=((ans<<bit)+i)%m;
        }
        return ans%m;
    }
};