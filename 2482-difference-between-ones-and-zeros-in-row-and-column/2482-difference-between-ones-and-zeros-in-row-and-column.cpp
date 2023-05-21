class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>&mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>row(n,0),col(m,0);
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!mat[i][j])
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j]=(m-row[i])+(n-col[j])-row[i]-col[j];
            }
        }
        return ans;
    }
};