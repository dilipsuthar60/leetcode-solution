class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) 
    {
        vector<int>ans;
        for(auto it:q)
        {
            int a=it[0];
            int b=it[1];
            int count=0;
            while(a!=b)
            {
                if(a>b)
                {
                    a/=2;
                }
                else
                {
                    b/=2;
                }
                count++;
            }
            ans.push_back(count+1);
        }
        return ans;
    }
};