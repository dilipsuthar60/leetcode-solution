class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                char ch=min(s[l],s[r]);
                s[l]=ch;
                s[r]=ch;
            }
            l++;
            r--;
        }
        return s;
    }
};