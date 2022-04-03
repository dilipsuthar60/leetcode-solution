class Solution {
public:
    int find(string&s)
    {
        return stoi(s.substr(0,2))*60+stoi(s.substr(3));
    }
    int convertTime(string s1, string s2) 
    {
        vector<int>v={60,15,5,1};
        int diff=find(s2)-find(s1);
        int count=0;
        for(auto &it:v)
        {
            count+=diff/it;
            diff=diff%it;
        }
        return count;
    }
};