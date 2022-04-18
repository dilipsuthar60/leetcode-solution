class Solution {
public:
    vector<vector<int>>dp;
    int ans=0;
    int find(int x,string &s)
    {
        vector<int>v={0,0};
        int len=0;
        for(auto it:dp[x])
        {
            len=find(it,s);
            if(s[x]!=s[it])
            {
                v.push_back(len);
            }
        }
        sort(v.rbegin(),v.rend());
        ans=max(ans,v[0]+v[1]+1);
        return v[0]+1;
    }
    int longestPath(vector<int>& parent, string s) 
    {
          ans=0;
        int n=parent.size();
        dp.resize(n+1);
        for(int i=1;i<n;i++)
        {
            dp[parent[i]].push_back(i);
        }
        find(0,s);
        return ans;
    }
};