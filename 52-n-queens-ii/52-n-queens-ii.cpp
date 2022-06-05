class Solution {
public:
    int count;
      bool is_safe(vector<string>&v,int row,int col)
    {
        for(int i=row-1;i>=0;i--)
        {
            if(v[i][col]=='Q')
            {
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(v[i][j]=='Q')
            {
                return false;
            }
        }
         for(int i=row-1,j=col+1;i>=0&&j<v.size();i--,j++)
        {
            if(v[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    void find(int n,vector<string>&v,int row)
    {
        if(row==n)
        {
            count++;
            return ;
        }
        for(int col=0;col<n;col++)
        {
            if(is_safe(v,row,col))
            {
                v[row][col]='Q';
                find(n,v,row+1);
                v[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) 
    {
         count=0;
        vector<vector<string>>ans;
        vector<string>v(n,string(n,'.'));
        find(n,v,0);
        return count;
    }
};