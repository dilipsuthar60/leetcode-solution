class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int count=0;
        for(auto it:grid)
        {
            for(auto value:it)
            {
                count+=(value<0);
            }
        }
        return count;
    }
};