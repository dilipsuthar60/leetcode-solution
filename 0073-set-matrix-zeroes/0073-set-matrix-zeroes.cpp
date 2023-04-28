class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>row(n);
        vector<int>col(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!mat[i][j])
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]||col[j])
                {
                    mat[i][j]=0;
                }
            }
        }
    }
};