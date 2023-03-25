class Solution {
public:
    vector<int>dp[100005];
    void find(int i,vector<int>&vis,long long &count)
    {
        count++;
        vis[i]=1;
        for(auto it:dp[i])
        {
            if(vis[it]==0)
            {
                find(it,vis,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& mat) 
    {
        for(auto it:mat)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
            
        }
    long long ans=0;
        vector<int>vis(n,0);
       
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                 long long count=0;
                find(i,vis,count);
                ans+=1ll*(count)*(n-count);
            }
        }
    
        return ans/2;;
    }
};