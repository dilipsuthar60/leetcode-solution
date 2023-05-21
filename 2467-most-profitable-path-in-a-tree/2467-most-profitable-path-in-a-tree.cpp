class Solution {
public:
int ans=0;
   vector<int>dp[200005];
   int depth[200005];
   int parent[200005];
   vector<int>amount;
   void find_p(int node,int d=0,int p=-1)
   {
       parent[node]=p;
       for(auto it:dp[node])
       {
           if(it!=p)
           {
               find_p(it,d+1,node);
           }
       }
   } 
   void find(int node,int d=0,int cost=0,int p=-1)
   {
       if(d<depth[node])
       {
           cost+=amount[node];
       }
       else if(depth[node]==d)
       {
           cost+=amount[node]/2;
       }
       // cout<<node<<"  "<<cost<<endl;
       if(node!=0&&dp[node].size()==1)
       {
           ans=max(ans,cost);
       }
       for(auto it:dp[node])
       {
           if(it!=p)
           {
               find(it,d+1,cost,node);
           }
       }
   }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& Amount) 
    {
        ans=-1e9;
        for(int i=0;i<200005;i++)
        {
            depth[i]=1e9;
        }
        amount=Amount;
        for(auto it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        find_p(0);
        int curr=bob;
        int d=0;
        while(curr!=-1)
        {
            depth[curr]=d;
            curr=parent[curr];
            d++;
        }
        find(0);
        return ans;
    }
};