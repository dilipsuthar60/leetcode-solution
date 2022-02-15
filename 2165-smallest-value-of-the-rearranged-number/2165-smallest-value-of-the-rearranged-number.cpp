class Solution {
public:
    long long smallestNumber(long long num) 
    {
        if(num==0)
        {
            return 0;
        }
        int zero=0;
        int sh=1;
        string s=to_string(num);
        for(int i=0;i<s.size();i++)
        {
            zero+=(s[i]=='0');
        }
        if(s[0]=='-')
        {
            s=s.substr(1);
            sort(s.begin(),s.end(),greater<int>());
            return -1*stoll(s);    
        }
        else
        {
            sort(s.begin(),s.end());
            int first=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!='0')
                {
                    first=i;
                    break;
                }
            }
            swap(s[0],s[first]);
            return stoll(s);
        }
        return 1;
    }
};