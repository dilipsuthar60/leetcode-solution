class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        vector<long long>prefix(n,0);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
            if(i==0)
            {
                prefix[i]=nums[i];
                continue;
            }
            prefix[i]=prefix[i-1]+nums[i];
        }
        sort(v.begin(),v.end());
        set<int>s;
        for(auto &[val,i]:v)
        {
            auto it=s.lower_bound(i);
            if(it!=s.end())
                right[i]=*it;
                if(it!=s.begin())
                {
                    it--;
                    left[i]=*it;
                }
            s.insert(i);
        }
        int mod=1e9+7;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int l=left[i];
            int r=right[i];
            long long val=1ll*nums[i]*(prefix[r-1]-((l!=-1)?prefix[l]:0));
            ans=max(ans,val);
        }
        return ans%mod;
    }
};