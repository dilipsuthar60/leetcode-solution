class Solution {
public:
    void find(vector<vector<int>>&v,int i,int j)
    {
        if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]==1)
        {
            return ;
        }
        v[i][j]=1;
        find(v,i-1,j);
        find(v,i+1,j);
        find(v,i,j-1);
        find(v,i,j+1);
    }
    int closedIsland(vector<vector<int>>& v) 
    {
        int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++)
        {
            find(v,i,0);
            find(v,i,m-1);
        }
        for(int i=0;i<m;i++)
        {
            find(v,0,i);
            find(v,n-1,i);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0)
                {
                    count++;
                    find(v,i,j);
                }
            }
        }
        return count;
    }
};