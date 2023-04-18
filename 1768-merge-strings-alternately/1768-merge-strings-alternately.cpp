class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        string ans(n+m,'a');
        int i,j;
        i=j=0;
        int index=0;
        while(i<n&&j<m)
        {
            ans[index++]=s1[i++];
            ans[index++]=s2[j++];
        }
        while(i<n)
        {
            ans[index++]=s1[i++];
        }
        while(j<m)
        {
            ans[index++]=s2[j++];
        }
        return ans;
    }
};