class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) 
    {
        int n=p.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({g[i],p[i]});
        }
        sort(v.rbegin(),v.rend());
        int bloom=0;
        int curr_p=0;
        for(int i=0;i<n;i++)
        {
            int pt=v[i].second;
            int gt=v[i].first;
            bloom=max(bloom,curr_p+pt+gt);
            curr_p=curr_p+pt;
        }
        return bloom;
    }
};