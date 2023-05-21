class Solution {
public:
    int minLength(string s) 
    {
        while(1)
        {
            int f=0;
            string ans="";
            for(int i=0;i<s.size();i++)
            {
                if(i+1<s.size()&&((s[i]=='A'&&s[i+1]=='B')||(s[i]=='C'&&s[i+1]=='D')))
                {
                    f=1;
                    s[i]='#';
                    s[i+1]='#';
                }
            }
            if(f==0)
            {
                break;
            }
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!='#')
                {
                    ans.push_back(s[i]);
                }
            }
            // cout<<ans<<" ";
            s=ans;
        }
        return s.size();
    }
};