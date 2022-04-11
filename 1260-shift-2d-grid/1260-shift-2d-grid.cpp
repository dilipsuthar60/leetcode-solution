class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>&mat, int k) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>temp(n,vector<int>(m,0));
        temp=mat;
        while(k--)
        {
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                temp[i][j]=mat[i][j-1];
            }
            for(int i=0;i<n-1;i++)
            {
                temp[i+1][0]=mat[i][m-1];
            }
            temp[0][0]=mat[n-1][m-1];
        }
            mat=temp;
        }
        return temp;
    }
};