class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>&mat) 
    {
        vector<vector<int>>ans;
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<int>v;
                if(mat[i][j]==1)
                {
                    mat[i][j]=0;
                    v.push_back(i);
                    v.push_back(j);
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vector<int>res;
                    while(q.size())
                    {
                        res.clear();
                        auto temp=q.front();
                        q.pop();
                        int x=temp.first;
                        int y=temp.second;
                        res.push_back(x);
                        res.push_back(y);
                        for(auto it:d)
                        {
                            int nx=x+it.first;
                            int ny=y+it.second;
                            if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]==1)
                            {
                                mat[nx][ny]=0;
                                q.push({nx,ny});
                            }
                        }
                    }
                    for(int i=0;i<res.size();i++)
                    {
                        v.push_back(res[i]);
                    }
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};