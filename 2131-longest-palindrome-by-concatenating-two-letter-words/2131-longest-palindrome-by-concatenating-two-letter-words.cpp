class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int count=0;
        unordered_map<string,int>mp;
        for(auto it:words)
        {
            string s=it;
            reverse(s.begin(),s.end());
            if(mp.find(s)!=mp.end())
            {
                count+=4;
                mp[s]--;
                if(mp[s]==0)
                {
                    mp.erase(s);
                }
            }
            else
            {
                mp[it]++;
            }
        }
        for(auto &[a,b]:mp)
        {
            if(a[0]==a[1]&&b)
            {
                count+=2;
                break;
            }
        }
        return count;
        // int dp[27][27];
        // memset(dp,0,sizeof(dp));
        // int len=0;
        // for(auto it:words)
        // {
        //     int first=it[0]-'a';
        //     int second=it[1]-'a';
        //     if(dp[second][first])
        //     {
        //         len+=4;
        //         dp[second][first]--;
        //     }
        //     else
        //     {
        //         dp[first][second]++;
        //     }
        // }
        // for(int i=0;i<26;i++)
        // {
        //     if(dp[i][i])
        //     {
        //         len+=2;
        //         break;
        //     }
        // }
        // return len;
    }
};