class Solution {
public:
    int minMaxDifference(int num) 
    {
        string s=to_string(num);
        int max_val=9;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]-'0')!=9)
            {
                max_val=(s[i]-'0');
                break;
            }
        }
        int min_val=s[0]-'0';
        string s1=s;
        string s2=s;
        for(int i=0;i<s.size();i++)
        {
            if((s1[i]-'0')==max_val)
            {
                s1[i]=('9');
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if((s2[i]-'0')==min_val)
            {
                s2[i]=('0');
            }
        }
        return stoi(s1)-stoi(s2);
    }
};