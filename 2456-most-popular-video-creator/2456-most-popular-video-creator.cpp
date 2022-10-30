class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) 
    {
        unordered_map<string,vector<pair<long long,string>>>dp;
        unordered_map<string,long long>mp;
        for(int i=0;i<c.size();i++)
        {
            mp[c[i]]+=views[i];
            dp[c[i]].push_back({views[i],ids[i]});
        }
        for(auto &it:dp)
        {
            sort(it.second.begin(),it.second.end(),[&](auto &a,auto &b){return a.first==b.first?a.second<b.second:a.first>b.first;});
        }
        long long max_val=0;
        for(auto &[a,b]:mp)
        {
            max_val=max(max_val,b);
        }
        vector<string>most;
        for(auto &[a,b]:mp)
        {
            if(max_val==b)
            {
                most.push_back(a);
            }
        }
        vector<vector<string>>ans;
        for(auto &it:most)
        {
            auto &vt=dp[it];
            ans.push_back({it,vt.front().second});
        }
        return ans;
    }
};