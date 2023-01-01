class Solution {
public:
    int countDigits(int num) 
    {
        int count=0;
        string d=to_string(num);
        for(int i=0;i<d.size();i++)
        {
            if(num%(d[i]-'0')==0)
            {
                count++;
            }
        }
        return count;
    }
};