class Solution {
public:
    vector<vector<int>>dp;
    void find(int x,int p,vector<int>&sub)
    {
        for(auto it:dp[x])
        {
            if(it!=p)
            {
               find(it,x,sub);
               sub[x]+=sub[it];
            }
        }
    }
    int countHighestScoreNodes(vector<int>& parents)
    {
        int n=parents.size();
        dp.resize(n);
        for(int i=1;i<n;i++)
        {
            dp[parents[i]].push_back(i);
        }
        vector<int>subtree(n,1);
        find(0,-1,subtree);
        map<long long ,long long ,greater<long long>>mp;
        for(int i=0;i<n;i++)
        {
            long long  pro=max(1,n-subtree[i]);
            for(auto it:dp[i])
            {
                pro=1ll*pro*subtree[it];
            }
            mp[pro]++;
        }
        return (mp.begin())->second;
    }
};