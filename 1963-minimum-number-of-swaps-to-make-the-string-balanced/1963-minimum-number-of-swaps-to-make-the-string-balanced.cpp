class Solution {
public:
    int minSwaps(string s) 
    {
        int n=s.size();
        stack<char>st;
        int open=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                open++;
            }
            else
            {
                if(open)
                {
                    open--;
                }
                else
                {
                    count++;
                }
            }
        }
        return (count+1)/2;
    }
};