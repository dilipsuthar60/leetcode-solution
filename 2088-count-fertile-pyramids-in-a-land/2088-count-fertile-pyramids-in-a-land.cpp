// void pyramids(vector<vector<int>> grid, int &ans){
//         int n = grid.size(), m = grid[0].size();
//         for(int i = 1; i < n; i++){
//             for(int j = 1; j < m - 1; j++){
//                 if(grid[i][j]){
//                     grid[i][j]= 1+ min(grid[i - 1][j],min(grid[i - 1][j - 1], grid[i - 1][j + 1]));
//                     ans += grid[i][j] - 1;
//                 }
//             }
//         }
//     }
//     int countPyramids(vector<vector<int>>& grid) {
//         int ans =0;
//         pyramids(grid, ans);
//         reverse(grid.begin(), grid.end());  
//         pyramids(grid, ans);
//         return ans;
//     }
class Solution {
public:
    int find(vector<vector<int>>mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(mat[i][j])
                {
                    mat[i][j]=1+min({mat[i-1][j-1],mat[i-1][j],mat[i-1][j+1]});
                    count+=mat[i][j]-1;
                }
            }
        }
        return count;
    }
    int countPyramids(vector<vector<int>>& grid) 
    {
        int ans=find(grid);
        reverse(grid.begin(),grid.end());
        ans+=find(grid);
        return ans;
    }
};