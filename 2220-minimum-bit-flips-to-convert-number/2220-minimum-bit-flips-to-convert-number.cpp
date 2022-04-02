class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int count=0;
        for(int i=0;i<32;i++)
        {
            int first=(1<<i)&start;
            int second=(1<<i)&goal;
            count+=(first!=second);
        }
        return count;
    }
};