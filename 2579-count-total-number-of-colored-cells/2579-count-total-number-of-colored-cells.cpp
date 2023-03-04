class Solution {
public:
    long long coloredCells(int n) {
        long long sum=0;
        long long curr=0;
        for(int i=1;i<=n;i++)
        {
            curr=2*i-1;
            sum+=curr;
        }
        for(int i=1;i<n;i++)
        {
            curr=2*i-1;
            sum+=curr;
        }
        return sum;
    }
};