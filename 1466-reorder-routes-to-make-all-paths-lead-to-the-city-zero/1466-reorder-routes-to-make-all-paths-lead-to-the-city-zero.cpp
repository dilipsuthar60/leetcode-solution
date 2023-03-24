class Solution {
public:
    int minReorder(int n, vector<vector<int>>& nums) 
    {
        vector<int>dp1[n+10];
        vector<int>dp2[n+10];
        for(auto it:nums)
        {
            int u=it[0];
            int v=it[1];
            dp1[u].push_back(v);
            dp2[v].push_back(u);
        }
        int cost=0;
        queue<int>q;
        q.push(0);
        vector<bool>vis(n+10,false);
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            vis[temp]=true;
            for(auto it:dp1[temp])
            {
               if(vis[it]==false)
               {
                    q.push(it);
                    cost++;
               }
            }
             for(auto it:dp2[temp])
            {
                 if(vis[it]==false)
                 {
                  q.push(it);   
                 }
            }
        }
        return cost;
    }
};