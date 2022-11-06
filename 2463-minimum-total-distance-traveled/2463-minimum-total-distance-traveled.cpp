class Solution {
public:
    long long dp[101][10005];
    long long find(vector<int>&r,vector<int>&f,int i,int j)
    {
        if(i==r.size())
        {
            return 0;
        }
        if(j==f.size())
        {
            return 1e18;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        long long first=abs(r[i]-f[j])+find(r,f,i+1,j+1);
        long long second=find(r,f,i,j+1);
        return dp[i][j]= min(first,second);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) 
    {
        memset(dp,-1,sizeof(dp));
        vector<int>v;
        for(auto it:factory)
        {
            for(int i=0;i<it[1];i++)
            {
                v.push_back(it[0]);
            }
        }
        sort(robot.begin(),robot.end());
        sort(v.begin(),v.end());
        return find(robot,v,0,0);
    }
};