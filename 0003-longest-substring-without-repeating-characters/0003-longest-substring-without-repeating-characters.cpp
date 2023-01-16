class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        // int i=0;
        int j=0;
        int len=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            while((i-j+1)>mp.size())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    mp.erase(s[j]);
                }
                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};