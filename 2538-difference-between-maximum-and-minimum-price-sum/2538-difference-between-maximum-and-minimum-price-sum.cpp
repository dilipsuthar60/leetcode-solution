class Solution {
public:
    vector<int>pt;
      int ans=0;
    vector<int>dp[100004];
    pair<long long,int> find(int node,int p=-1,long long wt=0)
    {
        wt+=pt[node];
        pair<long long,int>max1{wt,node};
        for(auto &it:dp[node])
        {
            if(p!=it)
            {
               max1=max(max1,find(it,node,wt));
            }
        }
        return max1;
    }
    void find1(int node,vector<long long>&dis,int p=-1,long long wt=0)
    {
        wt+=pt[node];
        dis[node]=max(dis[node],wt);
        for(auto it:dp[node])
        {
            if(p!=it)
            {
                find1(it,dis,node,wt);
            }
        }
    }
    long long maxOutput(int n, vector<vector<int>>& nums, vector<int>& price) 
    {
         pt=price;
         for(int i=0;i<nums.size();i++)
        {
            dp[nums[i][0]].push_back(nums[i][1]);
            dp[nums[i][1]].push_back(nums[i][0]);   
        }
        vector<long long>dis(n+1,0);
        auto [wt,node]=find(0);
        find1(node,dis);
        auto [wt1,node1]=find(node);
        find1(node1,dis);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dis[i]-pt[i]);
        }
        return ans;
    }
};