class Solution {
public:
    int n;
    long long max_val=0;
    vector<long long>parent,sum,rank;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void merge(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y)
        {
            return ;
        }
        // max_val=max(max_val,sum[y]);
        // parent[x]=y;
        if(rank[x]<rank[y])
        {
            rank[y]+=rank[x];
            parent[x]=y;
            sum[y]+=sum[x];
            max_val=max(max_val,sum[y]);
        }
        else
        {
            rank[x]+=rank[y];
            parent[y]=x;
            sum[x]+=sum[y];
            max_val=max(max_val,sum[x]);
        }
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& r)
    {
        n=nums.size();
        parent.resize(n+10);
        sum.resize(n+10);
        rank.resize(n+10);
        for(int i=0;i<n;i++)
        {
            rank[i]=1;
            sum[i]=nums[i];
            parent[i]=i;
        }
        vector<int>vis(n+1,0);
        vector<long long>ans(n,0);
         max_val=0;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=max_val;
            int index=r[i];
            vis[index]=1;
            max_val=max(max_val,1ll*nums[index]);
            if(index+1<n&&vis[index+1])
            {
                merge(index,index+1);
            }
            if(index-1>=0&&vis[index-1])
            {
                merge(index,index-1);
            }
        }
        return ans;
    }
};