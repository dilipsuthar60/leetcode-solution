class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long sum=0;
        vector<int>v;
        for(int i=0;i<word.size();i++)
        {
            sum=((sum*10)%m+word[i]-'0')%m;
            if(sum==0)
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
        return v;
    }
};