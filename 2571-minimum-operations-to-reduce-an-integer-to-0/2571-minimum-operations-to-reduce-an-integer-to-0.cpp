class Solution {
public:
    int find(int n)
    {
        if(__builtin_popcount(n)==1)
        {
            return 1;
        }
        return 1+min(find(n+(n&-n)),find(n-(n&-n)));
    }
    int minOperations(int val) 
    {
        return find(val);
    //    int result = 0;
    //  while(val!=0) {
    //     ++result;
    //     int firstbit = val&-val;
    //      cout<<firstbit<<endl;
    //     int pluscase = val+firstbit;
    //     if ((pluscase & (firstbit<<1)) == 0) {
    //         val+=firstbit;
    //     } else {
    //         val-=firstbit;
    //     }
    // }
    // return result;
    }
};