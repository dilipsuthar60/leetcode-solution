class Solution
{
public:
    int dp[21][100005];
    void find(vector<int>&nums)
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            dp[0][i]=nums[i];
        }
        for(int i=1;i<20;i++)
        {
            for(int node=0;node+(1<<i)<=n;node++)
            {
                dp[i][node]=max(dp[i-1][node],dp[i-1][node+(1<<(i-1))]);
            }
        }
    }
    int query(int l,int r)
    {
        int len=(r-l+1);
        int segment=(int)log2(len);
        return max(dp[segment][l],dp[segment][r-(1<<segment)+1]);
    }
    int binary(int l,int r,int target)
    {
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(query(l,mid)>target)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int>next(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()&&nums[i]>=nums[s.top()])
            {
                s.pop();
            }
            if(s.size())
            {
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> secondGreaterElement(vector<int>& nums) 
    {
        int n=nums.size();
        find(nums);
        vector<int>ans(n,-1);
        vector<int>ng=next(nums);
        for(int i=0;i<n;i++)
        {
            // cout<<ng[i]<<" ";
            if(ng[i]==-1)
            {
                continue;
            }
            int index=binary(ng[i]+1,n-1,nums[i]);
            if(index==-1)
            {
                continue;
            }
            ans[i]=nums[index];
        }
        return ans;
    }
};