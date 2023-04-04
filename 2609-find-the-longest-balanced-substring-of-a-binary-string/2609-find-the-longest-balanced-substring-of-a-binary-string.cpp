class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;)
        {
            int count0=0;
            int count1=0;
            while(i<n&&s[i]=='0')
            {
                count0++;
                i++;
            }
            while(i<n&&s[i]=='1')
            {
                count1++;
                i++;
            }
            ans=max(ans,2*min(count0,count1));
        }
        return ans;
    }
};