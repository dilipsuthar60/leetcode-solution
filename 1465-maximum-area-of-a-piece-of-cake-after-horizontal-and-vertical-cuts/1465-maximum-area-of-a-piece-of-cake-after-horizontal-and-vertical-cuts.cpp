class Solution {
public:
    int maxArea(int n, int m, vector<int>&h, vector<int>& v)
    {
        h.push_back(0);
        v.push_back(0);
        h.push_back(n);
        v.push_back(m);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        long long h_max=0;
        for(int i=1;i<h.size();i++)
        {
            h_max=max(h_max,0ll+h[i]-h[i-1]);
        }
        long long v_max=0;
        for(int i=1;i<v.size();i++)
        {
            v_max=max(v_max,0ll+v[i]-v[i-1]);
        }
        int mod=1e9+7;
        long long ans=((h_max%mod)*(v_max%mod))%mod;
        return (int)ans;
    }
};