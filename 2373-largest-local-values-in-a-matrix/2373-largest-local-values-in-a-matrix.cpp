class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                int local=-1e8;
                for(int x=-1;x<=1;x++)
                {
                    for(int y=-1;y<=1;y++)
                    {
                        local=max(local,mat[i+x][j+y]);
                    }
                }
                ans[i-1][j-1]=local;
            }
        }
        return ans;
    }
};