class Solution {
public:
    vector<long long> sumOfThree(long long num) 
    {
        long long val=num/3;
        if(3*val==num)
        {
            return {val-1,val,val+1};
        }
        return {};
    }
};