class Solution {
public:
    int dp[101][101];
    int find_cost(vector<int>&nums,int start,int end)
    {
        int cost=0;
        int mid_point=(start+end)/2;
        for(int i=start;i<=end;i++)
        {
            cost+=abs(nums[i]-nums[mid_point]);
        }
        return cost;
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
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return find(nums,0,k);
    }
};