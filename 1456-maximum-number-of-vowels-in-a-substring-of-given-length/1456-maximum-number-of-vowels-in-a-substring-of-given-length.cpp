class Solution {
public:
    bool find(char ch)
    {
        string s="aeiou";
        if(s.find(ch)!=string::npos)
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) 
    {
        int sum=0;
        int ans=0;
        for(int i=0;i<k;i++)
        {
            sum+=find(s[i]);
            ans=max(ans,sum);
        }
        for(int i=k,n=s.size();i<n;i++)
        {
            sum+=find(s[i]);
            sum-=find(s[i-k]);
            ans=max(ans,sum);
        }
        return ans;
    }
};