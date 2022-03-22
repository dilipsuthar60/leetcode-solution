class Solution {
public:
    int countCollisions(string s) 
    {
        int n=s.size();
        reverse(s.begin(),s.end());
        while(s.size()&&s.back()=='L')
        {
            s.pop_back();
        }
        reverse(s.begin(),s.end());
        int count_R=0;
        n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                count_R++;
            }
            else
            {
                ans+=(s[i]=='S')?count_R:count_R+1;
                count_R=0;
            }
        }
        return ans;
    }
};