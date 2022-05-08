class Solution {
public:
    string largestGoodInteger(string s) 
    {
        int n=s.size();
        int val=-1;
        for(int i=0;i+2<n;i++)
        {
            if(s[i]==s[i+1]&&s[i]==s[i+2])
            {
                val=max(val,s[i]-'0');
            }
        }
        if(val==-1)
        {
            return "";
        }
        return string(3,val+'0');
    }
};