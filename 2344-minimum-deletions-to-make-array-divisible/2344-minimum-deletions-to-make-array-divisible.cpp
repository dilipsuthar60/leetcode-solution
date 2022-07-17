class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& d) 
    {
        int f=d[0];
        for(auto it:d)
        {
            f=__gcd(it,f);
        }
        int index=0;
        sort(nums.begin(),nums.end());
        for(auto it:nums)
        {
            if(f%it==0)
            {
                return index;
            }
            index++;
        }
        return -1;
    }
};