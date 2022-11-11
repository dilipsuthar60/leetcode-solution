class Solution {
public:
    int n;
    vector<int>nums;
    vector<int>dp[100004];
    vector<int>dis;
    vector<int>st[55];
    // int h=nums[i];
    //     dis[i]=h1;
    //     ans[i]=-1;
    //     int val=-1;
    //     for(int w=1;w<=50;w++)
    //     {
    //         if(__gcd(h,w)==1)
    //         {
    //             if(d[w].size())
    //             {
    //                 int u=d[w].back();
    //                 if(dis[u]>val)
    //                 {
    //                     val=dis[u];
    //                     ans[i]=u;
    //                 }
    //             }
    //         }
    //     }
    //     d[h].push_back(i);
    //     for(auto x:adj[i])
    //     {
    //         if(x==p) continue;
    //         dfs(nums,ans,x,i,h1+1);
    //     }
    //     d[h].pop_back();
    void find(int node,vector<int>&ans,int d,int p=0)
    {
        int value=nums[node];
        dis[node]=d;
        int val=-1;
        for(int i=1;i<=50;i++)
        {
            if(__gcd(i,value)==1)
            {
                if(st[i].size())
                {
                    int get=st[i].back();
                    if(dis[get]>val)
                    {
                        val=dis[get];
                        ans[node]=get;
                    }
                }
            }
        }
        st[value].push_back(node);
        for(auto &it:dp[node])
        {
            if(it!=p)
            {
                find(it,ans,d+1,node);
            }
        }
        st[value].pop_back();
    }
    vector<int> getCoprimes(vector<int>& Nums, vector<vector<int>>& edges) 
    {
        dis=vector<int>(100004);
        n=Nums.size();
        nums=Nums;
        for(auto &it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<int>ans(n,-1);
        find(0,ans,1);
        return ans;
    }
};