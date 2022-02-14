class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int sum=A[0];
        int mn=A[0];
        int mx=A[0];
        int sum1=A[0];
        int sum2=A[0];
        for(int i=1;i<A.size();i++)
        {
            sum+=A[i];
            sum1=max(A[i],sum1+A[i]);
            sum2=min(A[i],sum2+A[i]);
            mx=max(mx,sum1);
            mn=min(mn,sum2);
        }
        // cout<<mx<<" "<<sum<<" "<<mn<<endl;
        if(sum==mn)
        {
            return mx;
        }
        return max(mx,sum-mn);
    }
};