class Solution {
public:
    bool detectCapitalUse(string s) 
    {
        int n=s.size();
        int f1=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                continue;
            }
            f1=0;
            break;
        }
         int f2=2;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                continue;
            }
            f2=0;
            break;
        }
         int f3=1;
        int is=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                is=i;
                continue;
            }
            else if(s[i]>='a'&&s[i]<='z')
            {
                continue;
            }
            else{
            f3=0;
            break;
            }
        }
        return f1||f2||(f3&&is==0);        
    }
};