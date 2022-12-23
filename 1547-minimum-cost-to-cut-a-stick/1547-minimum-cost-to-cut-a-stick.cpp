class Solution {
public:
    int dp[101][101];
    
    int find(vector<int>&nums,int i,int j)
    {
        if(i>j)
        {
            return 0;
        }
        int min_cost=1e9;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        for(int k=i;k<=j;k++)
        {
            min_cost=min(min_cost,(nums[j+1]-nums[i-1])+find(nums,i,k-1)+find(nums,k+1,j));
        }
        return dp[i][j] = min_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return find(cuts,1,cuts.size()-2);
    }
};