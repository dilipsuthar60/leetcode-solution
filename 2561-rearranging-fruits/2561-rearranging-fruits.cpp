class Solution {
public:
    long long minCost(vector<int>&nums1, vector<int>&nums2) 
    {
        unordered_map<int,int>mp;
        for(auto &it:nums1)
        {
            mp[it]++;
        }
        for(auto &it:nums2)
        {
            mp[it]--;
        }
        int mi=1e9;
        vector<int>element;
        for(auto &[a,b]:mp)
        {
            mi=min(mi,a);
            b=abs(b);
            if(b%2)
            {
                return -1;
            }
            for(int i=0;i<b/2;i++)
            {
                element.push_back(a);
            }
        }
        long long ans=0;
        sort(element.begin(),element.end());
        for(int i=0,n=element.size()/2;i<n;i++)
        {
            ans+=min(2*mi,element[i]);
        }
        return ans;
    }
};