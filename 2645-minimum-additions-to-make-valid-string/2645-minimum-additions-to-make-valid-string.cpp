class Solution {
public:
    int n;
    int find(string &s,int index,char want)
    {
        if(want=='d')
        {
            want='a';
        }
        if(index>=n)
        {
            if(want=='b')
            {
                return 2;
            }
            if(want=='c')
            {
                return 1;
            }
            return 0;
        }
        if(s[index]==want)
        {
            return find(s,index+1,want+1);
        }
        return 1+find(s,index,want+1);
    }
    int addMinimum(string s) 
    {
        n=s.size();
        return find(s,0,'a');
    }
};