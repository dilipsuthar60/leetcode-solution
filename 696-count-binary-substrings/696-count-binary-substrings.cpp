class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        vector<int>group;
        int n=s.size();
        int count=1;
        for(int i=1;i<=n;i++)
        {
            if(i<n&&s[i-1]==s[i])
            {
                count++;
            }
            else
            {
                group.push_back(count);
                count=1;
            }
        }
        
        int ans=0;
        for(int i=0;i<group.size();i++)
        {
            if(i)
            {
                ans+=min(group[i],group[i-1]);
            }
        }
        return ans;
    }
};