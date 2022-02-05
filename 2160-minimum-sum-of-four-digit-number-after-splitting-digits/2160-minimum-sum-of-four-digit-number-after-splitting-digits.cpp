class Solution {
public:
    bool check(string s)
    {
        if(s[0]=='0')
        {
            return false;
        }
        return true;
    }
    int minimumSum(int num) {
        string s=to_string(num);
        string now="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='0')
            {
                now.push_back(s[i]);
            }
        }
        s=now;
        sort(s.begin(),s.end());
        int ans=stoi(s);
        do
        {
            for(int i=0;i<s.size();i++)
            {
                string s1=s.substr(0,i);
                string s2=s.substr(i);
                if(s1.size()&&s2.size()&&check(s1)&&check(s2))
                {
                    int val1=stoi(s1);
                    int val2=stoi(s2);
                    ans=min(ans,val1+val2);
                }
            }
        }while(next_permutation(s.begin(),s.end()));
        
        return ans;
    }
};