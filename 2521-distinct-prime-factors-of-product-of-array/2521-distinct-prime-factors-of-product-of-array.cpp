class Solution {
public:
    bool find(int n)
    {
        if(n<2)
        {
            return false;
        }
        if(n==2)
        {
            return true;
        }
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int>s;
        long long p=1;
        for(auto it:nums)
        {
        for(int i=1;i<=sqrt(it);i++)
        {
            if(it%i==0)
            {
               s.insert(i);
                s.insert(it/i);
            }
        }
        }
        int count=0;
        for(auto it:s)
        {
            count+=find(it);
        }
        return count;
    }
};