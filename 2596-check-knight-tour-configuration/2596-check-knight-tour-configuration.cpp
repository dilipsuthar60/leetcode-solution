class Solution {
public:
    bool checkValidGrid(vector<vector<int>>&mat) 
    {
        int n=mat.size();
        vector<vector<int>>dp(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[mat[i][j]]={i,j};
            }
        }
        if(mat[0][0]!=0)
        {
            return false;
        }
        int prevx=0;
        int prevy=0;
        for(int i=1;i<n*n;i++)
        {
            int currx=dp[i][0];
            int curry=dp[i][1];
            if(!((abs(currx-prevx)==1&&abs(curry-prevy)==2)||(abs(currx-prevx)==2&&abs(curry-prevy)==1)))
            {
                return false;
            }
            prevx=currx;
            prevy=curry;
        }
        return true;
    }
};