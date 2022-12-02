class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& mat, string s) {
        map<int,set<int>>dp;
        for(auto &it:mat)
        {
            dp[it[0]].insert(it[1]);
            dp[it[1]].insert(it[0]);
        }
        queue<int>q;
        vector<vector<int>>now(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            if(dp[i].size()==1&&i!=0)
            {
                q.push(i);
            }
            now[i][s[i]-'a']=1;
        }
        while(q.size())
        {
            auto child=q.front();
            q.pop();
            for(auto &node:dp[child])
            {
                dp[node].erase(child);
                for(int i=0;i<26;i++)
                {
                    now[node][i]+=now[child][i];
                }
                if(node!=0&&dp[node].size()==1)
                {
                    q.push(node);
                }
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=now[i][s[i]-'a'];
        }
        return ans;
    }
};