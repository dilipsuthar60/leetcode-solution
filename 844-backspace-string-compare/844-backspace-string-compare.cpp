class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        int n=s.size();
        int m=t.size();
        int i=n-1;
        int j=m-1;
        while(1)
        {
            int d=0;
            while(i>=0&&(s[i]=='#'||d>0))
            {
                if(s[i]=='#')
                {
                    d++;
                }
                else
                {
                    d--;
                }
                i--;
            }
              d=0;
            while(j>=0&&(t[j]=='#'||d>0))
            {
                if(t[j]=='#')
                {
                    d++;
                }
                else
                {
                    d--;
                }
                j--;
            }
            if(i>=0&&j>=0&&(s[i]==t[j]))
            {
                i--;
                j--;
            }
            else
            {
                break;
            }
            
        }
        return i==-1&&j==-1;
    }
};