class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int len=grades.size();
        int l=0;
        int r=1e9;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(1ll*mid*(mid+1)/2<=len)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};