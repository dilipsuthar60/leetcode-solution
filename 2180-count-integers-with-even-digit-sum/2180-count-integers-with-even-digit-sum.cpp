class Solution {
public:
    int countEven(int num) 
    {
        int count=0;
        auto find=[&](int n)
        {
            int sum=0;
            while(n)
            {
                sum+=n%10;
                n=n/10;
            }
            return sum%2==0;
        };
        for(int i=1;i<=num;i++)
        {
            if(find(i))
            {
                count++;
            }
        }
        return count;
    }
};