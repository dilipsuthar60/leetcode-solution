class Solution {
public:
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<string,int>mp;
        int ans=0;
        sort(words.begin(),words.end(),[&](auto &a,auto b){return a.size()<b.size();});
        for(auto &it:words)
        {
            string s=it;
            for(int i=0;i<s.size();i++)
            {
                string new_string=s.substr(0,i)+s.substr(i+1);
                if(mp.find(new_string)!=mp.end())
                {
                    mp[s]=max(mp[s],mp[new_string]+1);
                }
                else
                {
                    mp[s]=max(mp[s],1);
                }
            }
        }
        for(auto &[a,b]:mp)
        {
            ans=max(ans,b);
        }
        return ans;
    }
};