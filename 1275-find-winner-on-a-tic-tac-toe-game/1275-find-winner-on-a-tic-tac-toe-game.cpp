class Solution {
public:
    int find(vector<vector<int>>&dp,int p)
    {
        if(dp[0][0]==p&&dp[1][1]==p&&dp[2][2]==p)
        {
            return p;
        }
        if(dp[0][2]==p&&dp[1][1]==p&&dp[2][0]==p)
        {
            return p;
        }
        for(int i=0;i<3;i++)
        {
            if(dp[i][0]==p&&dp[i][1]==p&&dp[i][2]==p)
            {
                return p;
            }
            if(dp[0][i]==p&&dp[1][i]==p&&dp[2][i]==p)
            {
                return p;
            }
        }
        return 0;
    }
    string tictactoe(vector<vector<int>>& moves) 
    {
        vector<vector<int>>dp(3,vector<int>(3,0));
        for(int i=0;i<moves.size();i++)
        {
            int val1=moves[i][0];
            int val2=moves[i][1];
            if(i%2==0)
            {
                dp[val1][val2]=1;
            }
            else
            {
                dp[val1][val2]=2;
            }
        }
        int f1=find(dp,1);
        if(f1==1)
        {
            return "A";
        }
        int f2=find(dp,2);
        if(f2==2)
        {
            return "B";
        }
        if(moves.size()==9)
        {
            return "Draw";
        }
        return "Pending";
    }
};