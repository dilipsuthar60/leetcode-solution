class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int ans=0;
    int find(int node,string &s,int p=-1)
    {
        int max1=0;
        int max2=0;
        for(auto &it:dp[node])
        {
            if(it==p)
            {
                continue;
            }
            int len=find(it,s,node);
            if(s[it]!=s[node])
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
        ans=max(ans,max1+max2+1);
        return max1+1;
    }
    int longestPath(vector<int>& parent, string s) 
    {
        n=parent.size();
        dp=vector<vector<int>>(n+1);
        for(int i=1;i<n;i++)
        {
            dp[parent[i]].push_back(i);
            dp[i].push_back(parent[i]);
        }
        find(0,s);
        return ans;
    }
};