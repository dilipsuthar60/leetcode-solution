class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
        sort(s.begin(),s.end());
        int first=0;
        int second=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                first=first*10+(s[i]-'0');
            }
            else
            {
                second=second*10+(s[i]-'0');
            }
        }
        return first+second;
    }
};