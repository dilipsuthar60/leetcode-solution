class Solution {
public:
    int it(string &s)
    {
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            sum=sum*10+(s[i]-'0');
        }
        return sum;
    }
    int find(string &s)
    {
        int ans=1e9+188;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string s1=s.substr(0,i+1);
            string s2=s.substr(i+1);
            ans=min(ans,it(s1)+it(s2));
        }
        return ans;
    }
    int splitNum(int num) 
    {
        int ans=1e9+100;
        string s=to_string(num);
        sort(s.begin(),s.end());
        do{
            ans=min(ans,find(s));
        }while(next_permutation(s.begin(),s.end()));
        return ans;
    }
};