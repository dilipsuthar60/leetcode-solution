class Solution {
public:
    int find(int x,vector<long long>&parent)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& q) 
    {
        int n=nums.size();
        vector<long long>parent(n),sum(n),vis(n,0);
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<n;i++)
        {
            sum[i]=nums[i];
        }
        vector<long long>ans;
        long long max_val=0;
        for(int i=n-1;i>=0;i--)
        {
            ans.push_back(max_val);
            int index=q[i];
            vis[index]=1;
            max_val=max(max_val,1ll*nums[index]);
            if(index-1>=0&&vis[index-1])
            {
                int first=find(index,parent);
                int second=find(index-1,parent);
                if(first!=second)
                {
                    sum[first]+=sum[second];
                    parent[second]=first;
                    max_val=max(max_val,sum[first]);
                }
            }
            if(index+1<n&&vis[index+1])
            {
                int first=find(index,parent);
                int second=find(index+1,parent);
                if(first!=second)
                {
                    sum[first]+=sum[second];
                    parent[second]=first;
                    max_val=max(max_val,sum[first]);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};