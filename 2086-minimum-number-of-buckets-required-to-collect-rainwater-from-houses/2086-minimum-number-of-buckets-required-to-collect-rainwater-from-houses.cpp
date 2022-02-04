class Solution {
public:
    int minimumBuckets(string s) {
        s='H'+s+'H';;
        int n=s.size();
        for(int i=1;i+1<n;i++)
            if(s[i]=='H'&&s[i-1]=='H'&&s[i+1]=='H') return -1;
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='H')
            {
                if(s[i-1]=='B')
                {
                    continue;
                }
                else if(s[i+1]=='.')
                {
                    s[i+1]='B';
                    ans++;
                }
                else if(s[i-1]=='.')
                {
                    s[i-1]='B';
                    ans++;
                }
            }
        }
        return ans;
    
    }
};