class Solution {
public:
    int passThePillow(int n, int time) 
    {
        int f=1;
        int curr=1;
        while(time--)
        {
            if(f)
            {
                curr++;
            }
            else
            {
                curr--;
            }
            if(curr==n)
            {
                f=0;
            }
            if(curr==1)
            {
                f=1;
            }
        }
        return curr;
    }
};