class Solution {
public:
    int ans=0;
    vector<int>dp[100004];
    int find(int node,string &s,int p=-1)
    {
        int max1=0;
        int max2=0;
        for(auto &it:dp[node])
        {
            if(p!=it)
            {
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
        }
        ans=max(ans,max1+max2+1);
        return max1+1;
    }
    int longestPath(vector<int>& parent, string s) 
    {
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]!=-1)
            {
                dp[parent[i]].push_back(i);
                dp[i].push_back(parent[i]);
            }
        }
        ans=0;
        find(0,s);
        return ans;
    }
};