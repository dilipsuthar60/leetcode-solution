class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<int>>dp2;
    int find_cost(vector<int>&nums,int start,int end)
    {
        if(dp2[start][end]!=-1)
        {
            return dp2[start][end];
        }
        int cost=0;
        int mid_point=(start+end)/2;
        for(int i=start;i<=end;i++)
        {
            cost+=abs(nums[i]-nums[mid_point]);
        }
        return dp2[start][end] = cost;
    }
    int find(vector<int>&nums,int index,int k)
    {
        if(k==1)
        {
            return find_cost(nums,index,nums.size()-1);
        } 
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        int ans=1e9;
        for(int i=index,n=nums.size();i<n;i++)
        {
            int cost=find_cost(nums,index,i);
            ans=min(ans,cost+find(nums,i+1,k-1));
        }
        return dp[index][k]=ans;
    }
    int minDistance(vector<int>&nums, int k)
    {
        int n=nums.size();
        dp=vector<vector<int>>(n+1,vector<int>(k+1,-1));
        dp2=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        sort(nums.begin(),nums.end());
        return find(nums,0,k);
    }
};