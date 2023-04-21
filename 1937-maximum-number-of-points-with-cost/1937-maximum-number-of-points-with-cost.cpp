class Solution {
public:
    long long maxPoints(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<long long>>dp(n,vector<long long>(m,0));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=mat[0][i];
        }
        for(int i=1;i<n;i++)
        {
            vector<long long>&value=dp[i-1];
            vector<long long>left(m,0);
            vector<long long>right(m,0);
            left[0]=value[0];
            right[m-1]=value[m-1];
            for(int j=1;j<m;j++)
            {
                left[j]=max(left[j-1]-1,value[j]);
            }
            for(int j=m-2;j>=0;j--)
            {
                right[j]=max(right[j+1]-1,value[j]);
            }
            for(int j=0;j<m;j++)
            {
                dp[i][j]=mat[i][j]+max(left[j],right[j]);
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};