class Solution {
public:
    int countLatticePoints(vector<vector<int>>& nums) {
        set<pair<int,int>>s;
        for(auto it:nums)
        {
            int x=it[0];
            int y=it[1];
            int r=it[2];
            for(int i=r-x;i<=r+x;i++)
            {
                for(int j=r-y;j<=r+y;j++)
                {
                    if(pow(i-x,2)+pow(j-y,2)<=r*r)
                    {
                        s.insert({i,j});
                    }
                }
            }
        }
        return s.size();
    }
};