class Solution {
public:
    int ans=0;
    bool v(string s)
    {
        int first=stoi(s.substr(0,2));
        int second=stoi(s.substr(3));
        return first<=23&&second<=59;
    }
    void find(string s,int index)
    {
        if(index==5)
        {
            ans+=v(s);
            return ;
        }
        if(s[index]!='?')
        {
            find(s,index+1);
        }
        else
        {
            int t=0;
            if(index==0)
            {
                t=2;
            }
            if(index==1||index==4)
            {
                t=9;
            }
            if(index==3)
            {
                t=5;
            }
            for(int i=0;i<=t;i++)
            {
                s[index]=char(i+'0');
                find(s,index+1);
                s[index]='?';
            }
        }
    }
    int countTime(string s) 
    {
        find(s,0);
        return ans;
    }
};