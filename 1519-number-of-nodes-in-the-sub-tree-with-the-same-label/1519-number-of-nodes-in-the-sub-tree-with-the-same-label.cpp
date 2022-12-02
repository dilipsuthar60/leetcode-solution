class Solution {
public:
    vector<int>dp[100005];
    vector<int>find(int node,int p,string &s,vector<int>&ans)
    {
        vector<int>freq(26,0);
        freq[s[node]-'a']++;
        for(auto it:dp[node])
        {
            if(it!=p)
            {
                vector<int>v=find(it,node,s,ans);
                for(int i=0;i<26;i++)
                {
                    freq[i]+=v[i];
                }
            }
        }
        ans[node]=freq[s[node]-'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>&mat, string labels) 
    {
        for(auto &it:mat)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<int>ans(n);
        find(0,-1,labels,ans);
        return ans;
    }
};