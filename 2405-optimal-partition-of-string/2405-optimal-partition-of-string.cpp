class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int ans=1;
        int mask=0;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<(s[i]-'a')))
            {
                mask=0;
                ans++;
                mask|=(1<<(s[i]-'a'));
            }
            else
            {
                mask|=(1<<(s[i]-'a'));
            }
        }
        return ans;
    }
};