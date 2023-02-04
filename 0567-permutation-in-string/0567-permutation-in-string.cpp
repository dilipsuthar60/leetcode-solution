class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size()>s2.size())
        {
            return false;
        }
        vector<int>first(26,0);
        vector<int>second(26,0);
        for(int i=0;i<s1.size();i++)
        {
            first[s1[i]-'a']++;
            second[s2[i]-'a']++;
        }
        if(first==second)
        {
            return true;
        }
        for(int i=s1.size();i<s2.size();i++)
        {
            second[s2[i-s1.size()]-'a']--;
            second[s2[i]-'a']++;
            if(first==second)
                {
                    return true;
                }
        }
        return false;
    }
};