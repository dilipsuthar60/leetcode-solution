class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        for(int i=0;i<=31;i++)
        {
            int val=1<<i;
            string str=to_string(val);
            sort(str.begin(),str.end());
            if(str==s)
            {
                return true;
            }
        }
        return false;
    }
};