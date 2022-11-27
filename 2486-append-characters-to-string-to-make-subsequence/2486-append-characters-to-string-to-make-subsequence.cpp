class Solution {
public:
    int appendCharacters(string s, string t) 
    {
        int j=0;
        int i=0;
        int n=s.size();
        int m=t.size();
        for(i=0,j=0;i<n&&j<m;)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(j==m)
        {
            return 0;
        }
        return m-j;
    }
};