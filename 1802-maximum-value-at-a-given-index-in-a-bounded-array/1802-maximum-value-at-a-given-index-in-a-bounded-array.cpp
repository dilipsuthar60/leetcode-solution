class Solution {
public:
    using ll=long long;
    ll calc(ll no,ll element)
    {
        return no*element-(no*(no+1)/2);
    }
    bool find(ll n,ll index,ll maxSum,ll mid)
    {
        ll left_sum=calc(min(index,mid-1),mid);
        left_sum+=max(0ll,index-mid+1);
        ll right_sum=calc(min(n-index-1,mid-1),mid);
        right_sum+=max(0ll,n-index-mid);
        return left_sum+mid+right_sum<=maxSum;
    }
    int maxValue(int n, int index, int maxSum) 
    {
        int l=1;
        int r=1e9;
        int ans=0;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(find(n,index,maxSum,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};