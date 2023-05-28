class Solution {
public:
    string removeTrailingZeros(string num) {
        while(num.size()&&num.back()=='0')
        {
            num.pop_back();
        }
        return num;
    }
};