class Solution {
public:
    vector<int>dp[20005+100];
    void find(int node,vector<int>&col,int p=-1)
    {
        for(int i=1;i<=4;i++)
        {
            int flag=1;
            for(auto it:dp[node])
            {
                if(col[it]==i)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                col[node]=i;
                break;
            }
        }
        for(auto it:dp[node])
        {
            if(col[it]==-1)
            {
                find(it,col,node);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        for(auto it:paths)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<int>col(n+1,-1);
        for(int i=1;i<=n;i++)
        {
            if(col[i]==-1)
              find(i,col);
        }
        col.erase(col.begin());
        return col;
    }
};