class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>&mat) 
    {
        vector<vector<int>>nums=mat;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                unordered_map<int,int>top,bottom;
                int x=i-1;
                int y=j-1;
                while(x>=0&&y>=0)
                {
                    top[mat[x][y]]++;
                    x--;
                    y--;
                }
                x=i+1;
                y=j+1;
                while(x<n&&y<m)
                {
                    bottom[mat[x][y]]++;
                    x++;
                    y++;
                }
                nums[i][j]=abs((int)top.size()-(int)bottom.size());
            }
        }
        return nums;
    }
};