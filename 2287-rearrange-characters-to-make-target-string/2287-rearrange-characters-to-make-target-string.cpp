class Solution {
public:
    int rearrangeCharacters(string s, string t) 
    {
        int n=s.size();
        int count=0;
        unordered_map<char,int>mp1,mp2;
        for(auto &it:s)
        {
            mp1[it]++;
        }
        for(auto &it:t)
        {
            mp2[it]++;
        }
        for(auto &[a,b]:mp2)
        {
            mp1[a]/=b;
        }
        int ans=1e8;
        for(auto &[a,b]:mp2)
        {
          ans=min(ans,mp1[a]);
        }
        
        return ans;
    }
};