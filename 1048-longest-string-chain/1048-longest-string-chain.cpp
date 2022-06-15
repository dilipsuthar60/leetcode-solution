class Solution {
public:
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<string,int>mp;
        int ans=0;
        int n=words.size();
        sort(words.begin(),words.end(),[&](auto &a,auto b){return a.size()<b.size();});
        auto find=[&](string &s,string &p)
        {
            int n=s.size();
            int m=p.size();
            if(n!=m+1)
            {
                return false;
            }
            int i=0;
            int j=0;
            while(i<n&&j<m)
            {
                if(s[i]==p[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i++;
                }
            }
            return j==m;
        };
        vector<int>dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(find(words[i],words[j])&&dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};