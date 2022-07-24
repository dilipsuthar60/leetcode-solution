class Solution {
public:
    char repeatedCharacter(string s) {
        int mask=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<(s[i]-'a')))
            {
                return s[i];
            }
            else
            {
                mask|=(1<<(s[i]-'a'));
            }
        }
        return '1';
    }
};