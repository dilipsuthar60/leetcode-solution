class Solution {
public:
    bool checkValidGrid(vector<vector<int>>&mat) 
    {
        int n=mat.size();
        if(mat[0][0]!=0)
        {
            return false;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        int next=1;
        vector<pair<int,int>>d={{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            int f=0;
            for(auto &it:d)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<n&&mat[nx][ny]==next)
                {
                    f=1;
                    q.push({nx,ny});
                    break;
                }
            }
            if(f)
            {
                next++;
            }
            else if(next!=n*n)
            {
                return false;
            }
        }
        return true;
    }
};