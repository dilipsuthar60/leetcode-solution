class Solution {
public:
    int find(vector<vector<int>>&mat,int a,int b)
    {
        int count=0;
        int n=mat.size();
        int m=mat[0].size();
        int bound=m;
        for(int i=a;i<n;i++)
        {
            for(int j=b;j<bound;j++)
            {
                if(mat[i][j])
                {
                    count++;
                }
                else
                {
                    bound=j;
                }
            }
        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat)
    {
        int count=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int>dp(m,1);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    dp[k]&=mat[j][k];
                }
                int ans=0;
                for(auto it:dp)
                {
                    if(it==0)
                    {
                        ans=0;
                    }
                    else
                    {
                        ans++;
                    }
                    count+=ans;
                }
            }
        }
        return count;
    }
};