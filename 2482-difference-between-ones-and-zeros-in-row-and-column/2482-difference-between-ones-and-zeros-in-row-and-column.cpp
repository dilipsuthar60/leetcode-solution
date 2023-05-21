class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>&mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>row,col;
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            int zero=count(mat[i].begin(),mat[i].end(),0);
            int one=count(mat[i].begin(),mat[i].end(),1);
            row.push_back({zero,one});
        }
        for(int j=0;j<m;j++)
        {
            int zero=0;
            int one=0;
            for(int i=0;i<n;i++)
            {
                zero+=(mat[i][j]==0);
                one+=(mat[i][j]==1);
            }
            col.push_back({zero,one});
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j]=row[i].second+col[j].second-(row[i].first+col[j].first);
            }
        }
        return ans;
    }
};