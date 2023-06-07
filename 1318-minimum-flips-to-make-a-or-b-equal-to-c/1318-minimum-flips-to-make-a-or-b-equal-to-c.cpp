class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int count=0;
        while(a||b||c)
        {
            int bit_a=a&1;
            int bit_b=b&1;
            int bit_c=c&1;
            if((bit_a|bit_b)!=bit_c)
            {
                if(bit_c)
                {
                    count++;
                }
                else
                {
                    count+=bit_a+bit_b;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return count;
    }
};