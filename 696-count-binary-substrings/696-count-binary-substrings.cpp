class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        vector<int>group;
        int n=s.size();
        for(int i=0;i<n;)
        {
            int count=0;
            char ch=s[i];
            int j=i;
            while(j<n&&ch==s[j])
            {
                j++;
                count++;
            }
            if(count)
            {
                group.push_back(count);
            }
            i=j;
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