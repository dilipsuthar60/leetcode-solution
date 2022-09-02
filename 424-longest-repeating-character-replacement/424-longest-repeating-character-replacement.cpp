class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int ans=0;
        unordered_map<char,int>mp;
        for(int i=0,j=0,n=s.size(),max_count=0;i<n;i++)
        {
            mp[s[i]]++;
            max_count=max(max_count,mp[s[i]]);
            while(i-j+1-max_count>k)
            {
                mp[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
