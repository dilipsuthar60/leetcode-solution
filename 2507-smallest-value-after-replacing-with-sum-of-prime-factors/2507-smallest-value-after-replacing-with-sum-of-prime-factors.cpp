class Solution {
public:
int find_factor(int n)
{
    int sum=0;
    for(int i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            sum+=(i);
            n=n/i;
        }
    }
    return sum;
}
    int smallestValue(int n) {
        if(n<=4)
        {
            return n;
        }
        while(1)
        {
            int now=find_factor(n);
            if(now==n)
            {
                return now;
            }
            n=now;
        }
        return 0;
    }
};