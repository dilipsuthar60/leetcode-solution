class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int l=-1e9;
        int r=1e9;
        int ans=0;
        auto find=[&](int mid)
        {
            int count=0;
            for(auto it:mat)
            {
                count+=upper_bound(it.begin(),it.end(),mid)-it.begin();
            }
            return count;
        };
        while(l<=r)
        {
            int mid=(l+r)/2;
            int val=find(mid);
            if(val>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};