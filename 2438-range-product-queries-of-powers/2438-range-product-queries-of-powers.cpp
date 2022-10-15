class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) 
    {
        vector<int>v;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
            {
                v.push_back(1<<i);
            }
        }
        int mod=1e9+7;
        vector<int>ans;
        for(int i=0;i<q.size();i++)
        {
            long long val=1;
            int l=q[i][0];
            int r=q[i][1];
            for(int i=l;i<=r;i++)
            {
                val*=v[i];
                val%=mod;
            }
            ans.push_back(val);
        }
        return ans;
    }
};