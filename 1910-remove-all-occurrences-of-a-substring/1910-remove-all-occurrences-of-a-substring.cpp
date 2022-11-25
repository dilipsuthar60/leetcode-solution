class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        int j=0;
        int sizeOfString=s.size();
        for(int i=0;i<sizeOfString;i++)
        {
            s[j++]=s[i];
            if(j>=part.size()&&s.substr(j-part.size(),part.size())==part)
            {
                j-=part.size();
            }
        }
        return s.substr(0,j);
    }
};