class Solution {
public:
    const int mod=1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    { 
        using ll=long long;
        int n=nums1.size();
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=abs(nums1[i]-nums2[i]);
        }
        ll ans=INT_MAX;
        set<ll>s(nums1.begin(),nums1.end());
        for(int i=0;i<n;i++)
        {
            auto it=s.lower_bound(nums2[i]);
            ll diff=abs(nums1[i]-nums2[i]);
            if(it!=s.end())
            {
                ans=min(ans,-diff+abs(*it-nums2[i]));
            }
            if(it!=s.begin())
            {
                it--;
                ans=min(ans,-diff+abs(*it-nums2[i]));
            }
        }
        return (1ll*sum+1ll*ans)%mod;
    }
};