class Solution {
public:
    int find(string &s,int index)
    {
        int count0=0;
        int count1=0;
        int f=0;
        for(int i=index;i<s.size();i++)
        {
            if(s[i]=='0'&&f==0)
            {
                count0++;
            }
            else if(s[i]=='1')
            {
                f=1;
                count1++;
            }
            else
            {
                break;
            }
        }
        return 2*min(count0,count1);
    }
    int findTheLongestBalancedSubstring(string s) {
        int ans=0;
        for(int i=0,n=s.size();i<n;i++)
        {
            if(s[i]=='0')
            ans=max(ans,find(s,i));
        }
        return ans;
    }
};