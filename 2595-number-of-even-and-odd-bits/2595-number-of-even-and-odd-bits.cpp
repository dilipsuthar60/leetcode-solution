class Solution {
public:
    vector<int> evenOddBit(int n) {
        int e=0;
        int o=0;
        for(int i=0;i<31;i++)
        {
            if(n&(1<<i))
            {
                if(i&1)
                {
                    o++;
                }
                else
                {
                    e++;
                }
            }
        }
        return {e,o};
    }
};