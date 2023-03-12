class Solution {
public:
    int findMinimumTime(vector<vector<int>>&nums) 
    {
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a[1]<b[1];});
        int vis[2001];
        fill(vis,vis+2001,0);
        int count=0;
        for(auto it:nums)
        {
            int left=it[0];
            int right=it[1];
            int d=it[2];
            for(int i=right;i>=left;i--)
            {
                if(vis[i])
                {
                    d--;
                }
            }
            for(int i=right;d>0&&i>=left;i--)
            {
                if(vis[i]==0)
                {
                    count++;
                    d--;
                    vis[i]=1;
                }
            }
        }
    return count;
    }
};