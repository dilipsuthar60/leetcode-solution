class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int ans=1e9;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(words[i]==target)
            {
                int dist=abs(i-startIndex);
                ans=min(ans,dist);
                ans=min(ans,n-dist);
            }
        }
        return ans==1e9?-1:ans;
    }
};