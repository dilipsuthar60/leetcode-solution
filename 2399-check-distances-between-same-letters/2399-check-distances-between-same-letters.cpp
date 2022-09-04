class Solution {
public:
    bool checkDistances(string s, vector<int>& dist) 
    {
        vector<int>mp(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]-'a']==-1)
            {
                mp[s[i]-'a']=i;
            }
            else
            {
                int d=i-mp[s[i]-'a']-1;
                if(dist[s[i]-'a']!=d)
                {
                    return false;
                }
            }
        }
        return true;
    }
};