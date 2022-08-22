class Solution {
public:
    int n,m;
    using ll =long long;
    ll find(vector<int>&nums1,vector<int>&nums2,ll product)
    {
        ll count=0;
        for(int i=0;i<n;i++)
        {
            long long val=nums1[i];
             if(val>=0)
            {
                ll l=0;
                ll r=m-1;
                ll ans=-1;
                while(l<=r)
                {
                    ll mid=(l+r)/2;
                    if((val*nums2[mid])<=product)
                    {
                        ans=mid;
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
                count+=ans+1;
            }
            else
            {
                ll l=0;
                ll r=m-1;
                ll ans=m;
                while(l<=r)
                {
                    ll mid=(l+r)/2;
                    if((val*nums2[mid])<=product)
                    {
                        ans=mid;
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                count+=m-ans;
            }
        }
        return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        n=nums1.size();
        m=nums2.size();
        ll f1=nums1[0];
        ll f2=nums1[n-1];
        ll f3=nums2[0];
        ll f4=nums2[m-1];
        ll l=min({f1*f2,f1*f3,f1*f4,f2*f3,f2*f4,f3*f4});
        ll r=max({f1*f2,f1*f3,f1*f4,f2*f3,f2*f4,f3*f4});
        ll ans=-1;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(find(nums1,nums2,mid)>=k)
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