class Solution {
public:
    int addMinimum(string s) 
    {
        int n=s.size();
        int i=0;
        int ans=0;
        while(i<n)
        {
            int count=0;
            if(s[i]=='a')
            {
                i++;
                count++;
            }
            if(i<n&&s[i]=='b')
            {
                i++;
                count++;
            }
            if(i<n&&s[i]=='c')
            {
                i++;
                count++;
            }
            ans+=3-count;
        }
        return ans;
    }
};