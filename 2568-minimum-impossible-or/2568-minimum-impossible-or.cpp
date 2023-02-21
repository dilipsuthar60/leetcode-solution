class Solution {
public:
    int minImpossibleOR(vector<int>&arr) 
    {
    set<int>s(arr.begin(),arr.end());
        long long x=1;
        while(s.find(x)!=s.end())
        {
            x*=2;
        }
        return x;
    }
};