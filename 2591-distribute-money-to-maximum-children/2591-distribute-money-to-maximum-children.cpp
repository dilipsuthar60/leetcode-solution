class Solution {
public:
    int distMoney(int m, int c) 
    {
        if(m<c)
        {
            return -1;
        }
        vector<int>v(c,1);
        m-=c;
        for(int i=0;i<c;i++)
        {
            if(v[i]+7<=m)
            {
                v[i]+=7;
                m-=7;
            }
        }
        v.back()+=m;
        for(int i=c-1;i>=1;i--)
        {
            if(v[i]==4)
            {
                v[i]--;
                v[i-1]++;
            }
        }
        int count=0;
        for(int i=0;i<c;i++)
        {
            if(v[i]==8)
            {
                count++;
            }
        }
        return  count;
    }
};