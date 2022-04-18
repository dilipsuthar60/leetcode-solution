class Solution {
public:
    vector<vector<int>>dp;
    int ans=0;
    int find(int x,string &s)
    {
        int max1=0;
        int max2=0;
        for(auto it:dp[x])
        {
            int len=find(it,s);
            if(s[x]!=s[it])
            {
                if(len>=max1)
                {
                    max2=max1;
                    max1=len;
                }
                else if(len>=max2)
                {
                    max2=len;
                }
            }
        }
        // sort(v.rbegin(),v.rend());
        ans=max(ans,max1+max2+1);
        return max1+1;
    }
    int longestPath(vector<int>& parent, string s) 
    {
          ans=0;
        int n=parent.size();
        dp.resize(n+1);
        for(int i=1;i<n;i++)
        {
            dp[parent[i]].push_back(i);
        }
        find(0,s);
        return ans;
    }
};