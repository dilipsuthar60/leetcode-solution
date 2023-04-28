class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int row_zero=false;
        int col_zero=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!mat[i][j])
                {
                    if(i==0)
                    {
                        row_zero=true;
                    }
                    if(j==0)
                    {
                        col_zero=true;
                    }
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][0]==0||mat[0][j]==0)
                {
                    mat[i][j]=0;
                }
            }
        }
        if(row_zero)
        {
            for(int i=0;i<m;i++)
            {
                mat[0][i]=0;
            }
        }
        if(col_zero)
        {
            for(int i=0;i<n;i++)
            {
                mat[i][0]=0;
            }
        }
    }
};