class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        // int i=0;
        int j=0;
        int len=0;
        int mp[256];
        memset(mp,0,sizeof(mp));
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]==0)
            {
                count++;
            }
            mp[s[i]]++;
            while((i-j+1)>count)
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};