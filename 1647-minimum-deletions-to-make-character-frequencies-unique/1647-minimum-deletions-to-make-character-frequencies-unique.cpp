class Solution {
public:
    int minDeletions(string s)
    {
        int n=s.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++)
        {
            v[s[i]-97]++;
        }
        sort(v.rbegin(),v.rend());
        int count=0;
        int max_freq=s.size();
        for(int i=0;i<26&&v[i]>0;i++)
        {
            if(v[i]>max_freq)
            {
                count+=v[i]-max_freq;
                v[i]=max_freq;
            }
            max_freq=max(0,v[i]-1);
        }
        return count;
    }
};