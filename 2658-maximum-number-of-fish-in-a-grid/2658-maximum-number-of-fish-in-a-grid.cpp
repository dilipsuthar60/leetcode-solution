class Solution {
public:
    vector<vector<int>>vis;
    void find(vector<vector<int>>&mat,int i,int j,int &sum)
    {
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||mat[i][j]==0||vis[i][j]==1)
        {
            return ;
        }
        vis[i][j]=1;
        sum+=mat[i][j];
        find(mat,i+1,j,sum);
        find(mat,i-1,j,sum);
        find(mat,i,j+1,sum);
        find(mat,i,j-1,sum);
    }
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vis=vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                {
                    int sum=0;
                    find(grid,i,j,sum);
                    // cout<<sum<<endl;
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};