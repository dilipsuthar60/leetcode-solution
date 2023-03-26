class Solution {
public:
    int kItemsWithMaximumSum(int o, int z, int n, int k) 
    {
        int count=0;
        while(o&&k)
        {
            o--;
            count++;
            k--;
        }
        while(z&&k)
        {
            z--;
            k--;
        }
        while(n&&k)
        {
            n--;
            count--;
            k--;
        }
        return count;
    }
};