class Solution {
public:
    // int dp[109][109]
    map<pair<int,int>,int>mp;
    bool find(string &s,int i,int open)
    {
        if(open<0)
        {
            return 0;
        }
        if(i==s.size())
        {
            return open==0;
        }
        if(mp.find({i,open})!=mp.end())
        {
            return mp[{i,open}];
        }
        int ans=0;
        if(s[i]=='(')
        {
           ans=find(s,i+1,open+1);
        }
        else if(s[i]==')')
        {
            ans=find(s,i+1,open-1);
        }
        else
        {
            ans=find(s,i+1,open-1)||find(s,i+1,open)||find(s,i+1,open+1);
        }
        return mp[{i,open}]=ans;
    }
    bool checkValidString(string s)
    {
        mp.clear();
        return find(s,0,0)==1;
    }
};