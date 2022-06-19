class Solution {
public:
    
    int longestSubsequence(string s, int k) 
    {
        int len=0;
        long long val=0;
        int n=s.size();
        int f=0;
        int index=-1;
        for(int i=n-1;~i;i--)
        {
            if(s[i]=='0')
            {
                len++;
            }
            else
            {
                if(len<=32&&((val+(1ll<<len))<=k))
                {
                    val=val+(1ll<<len);
                    len++;
                }
            }
        }
        return len;
    }
};