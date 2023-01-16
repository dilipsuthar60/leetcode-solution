class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) 
    {
      vector<vector<int>> mat(n, vector<int>(n));
        for (auto i : q) {
            int a = i[0];
            int b = i[1];
            int c = i[2];
            int d = i[3];
            mat[a][b]++;
            if(c+1<n)
            {
                mat[c+1][b]--;
            }
            if(d+1<n)
            {
                mat[a][d+1]--;
            }
            if(c+1<n&&d+1<n)
            mat[c+1][d+1]++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int i=1;i<n;i++)
            {
                mat[i][j]+=mat[i-1][j];
            }
        }
        return mat;
    }
};