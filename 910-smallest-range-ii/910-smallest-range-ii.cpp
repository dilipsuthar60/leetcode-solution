class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i]-k,i});
            v.push_back({nums[i]+k,i});
        }
        sort(v.begin(),v.end());
        vector<int>take(n,0);
        int j=0;
        int i=0;
        int count=0;
        while(count<n)
        {
            if(take[v[i].second]==0)
            {
                count++;
            }
            take[v[i].second]++;
            i++;
        }
        int ans=v[i-1].first-v[j].first;
        while(i<v.size())
        {
            if(take[v[j].second]==1)
            {
                count--;
            }
            take[v[j].second]--;
            j++;
            while(count<n&&i<v.size())
            {
                if(take[v[i].second]==0)
                {
                    count++;
                }
                take[v[i].second]++;
                i++;
            }
            if(count==n)
            {
                ans=min(ans,v[i-1].first-v[j].first);
            }
        }
        return ans;
    }
};