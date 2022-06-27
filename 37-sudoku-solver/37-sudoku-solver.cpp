class Solution {
public:
    bool find(vector<vector<char>>&mat,vector<int>&row,vector<int>&col,vector<vector<int>>&grid,int curr)
    {
        int i=curr/9;
        int j=curr%9;
        if(i==mat.size())
        {
            return true;
        }
        if(mat[i][j]!='.')
        {
            return find(mat,row,col,grid,curr+1);
        }
        else
        {
            for(int num=1;num<=9;num++)
            {
                if((row[i]&(1<<num))==0&&(col[j]&(1<<num))==0&&(grid[i/3][j/3]&(1<<num))==0)
                {
                   
                    mat[i][j]=num+'0';
                    row[i]^=(1<<num);
                    col[j]^=(1<<num);
                    grid[i/3][j/3]^=(1<<num);
                    if(find(mat,row,col,grid,curr+1))
                              {
                                  return true;
                              }
                    row[i]^=(1<<num);
                    col[j]^=(1<<num);
                    grid[i/3][j/3]^=(1<<num);
                    mat[i][j]='.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>&mat) 
    {
        vector<int>row(9,0);
        vector<int>col(9,0);
        vector<vector<int>>grid(3,vector<int>(3,0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]!='.')
                {
                int val=1<<(mat[i][j]-'0');
                row[i]|=val;
                col[j]|=val;
                grid[i/3][j/3]|=val;
                }
            }
        }
        find(mat,row,col,grid,0);
        // return mat;
    }
};