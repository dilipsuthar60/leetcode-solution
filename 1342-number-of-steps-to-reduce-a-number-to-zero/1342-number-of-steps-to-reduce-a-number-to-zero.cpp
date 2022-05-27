class Solution {
public:
    int numberOfSteps(int num) 
    {
        if(num==0)
        {
            return 0;
        }
        if(num&1)
        {
            return 1+numberOfSteps(num-1);
        }
        return 1+numberOfSteps(num/2);
    }
};