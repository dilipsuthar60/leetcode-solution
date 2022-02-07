class Solution {
public:
    char findTheDifference(string s, string t)
    {
        char sum1=0;
        for(char i:s)
        {
            sum1=sum1^i;
        }
        for(char i:t)
        {
            sum1=sum1^i;
        }
        return sum1;
        // int count[26]={0};
        // for(int i=0;i<s.size();i++)
        // {
        //     count[s[i]-97]++;
        // }
        // for(int i=0;i<t.size();i++)
        // {
        //     count[t[i]-97]--;
        // }
        // for(int i=0;i<26;i++)
        // {
        //     if(count[i]==-1)
        //         return (char)(i+97);
        // }
        // return 0;
    }
};