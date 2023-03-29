class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n+1);
        vector<int>ind(n,0);
        for(auto &it:edges)
        {
            ind[it[0]]++;
            ind[it[1]]++;
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==1&&coins[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            for(auto &it:dp[temp])
            {
                if(ind[it]>=1)
                {
                    ind[it]--;
                    if(ind[it]==1&&coins[it]==0)
                    {
                        q.push(it);
                    }
                }
            }
            ind[temp]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(ind[i]==1&&coins[i]==1)
            {
                q.push(i);
            }
        }
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            for(auto &it:dp[temp])
            {
                if(ind[it]>=1)
                {
                    ind[it]--;
                    if(ind[it]==1)
                    {
                        ind[it]=0;
                    }
                }
            }
            ind[temp]=0;
        }
        int count=0;
        for(auto &it:edges)
        {
            if(ind[it[0]]&&ind[it[1]])
            {
                count++;
            }
        }
        return 2*count;
    }
};