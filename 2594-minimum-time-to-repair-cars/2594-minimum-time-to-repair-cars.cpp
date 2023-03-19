class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        int n=ranks.size();
        long long ans=0;
        long long l=1;
        long long r=1e18;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long cost=0;
            for(int i=0;i<n;i++)
            {
                cost+=sqrtl(mid/ranks[i]);
            }
            if(cost>=cars)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};