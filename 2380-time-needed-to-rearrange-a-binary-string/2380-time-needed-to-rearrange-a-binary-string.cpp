class Solution {
public:
    int secondsToRemoveOccurrences(string s) 
    {
        int n=s.size();
        int count=0;
        while(1)
        {
            int f=0;
            for(int i=0;i<n-1;i++)
            {
                if(s[i]=='0'&&s[i+1]=='1')
                {
                    f=1;
                    s[i]='1';
                    s[i+1]='0';
                    i++;
                }
            }
            // cout<<s<<endl;
            if(f)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};