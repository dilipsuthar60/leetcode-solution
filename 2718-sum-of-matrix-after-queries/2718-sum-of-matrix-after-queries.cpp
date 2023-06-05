class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) 
    {
        int row_count=n;
        int col_count=n;
        long long cost=0;
        unordered_map<int,int>row,col;
        for(int i=q.size()-1;i>=0;i--)
        {
            int type=q[i][0];
            int index=q[i][1];
            int value=q[i][2];
            if(type==0)
            {
                if(row.find(index)==row.end())
                {
                    row[index]++;
                    cost+=1ll*value*col_count;
                    row_count--;
                }
            }
            else
            {
                if(col.find(index)==col.end())
                {
                    col[index]++;
                    cost+=1ll*value*row_count;
                    col_count--;
                }
            }
        }
        return cost;
        
    }
};