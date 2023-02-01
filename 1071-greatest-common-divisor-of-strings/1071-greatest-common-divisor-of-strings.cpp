class Solution {
public:
    string gcdOfStrings(string str1, string str2)
    {
        int n=str1.size();
        int m=str2.size();
        return (str1+str2==str2+str1)?str2.substr(0,__gcd(n,m)):"";
    }
};