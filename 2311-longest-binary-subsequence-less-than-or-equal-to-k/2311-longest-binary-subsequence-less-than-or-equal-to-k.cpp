class Solution {
public:
    
    int longestSubsequence(string s, int k) 
    {
        int len=0;
        long long val=0;
        int n=s.size();
        int f=0;
        int index=-1;
        for(int i=n-1;~i&&len<=31;i--)
        {
            if(s[i]=='0')
            {
                len++;
            }
            else
            {
                val=val|(1ll<<len);
                if(val<=k)
                {
                    len++;
                }
                else
                {
                    break;
                }
            }
            index=i;
        }
        while(index>0)
        {
            index--;
            if(s[index]=='0')
            {
                len++;
            }
        }
        return len;
    }
};