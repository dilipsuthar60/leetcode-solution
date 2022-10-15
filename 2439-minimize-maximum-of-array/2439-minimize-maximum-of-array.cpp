class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l=0;
        int r=1e9;
        int ans=0;
        int n=nums.size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            vector<long long>temp(nums.begin(),nums.end());
            for(int i=n-1;i>=1;i--)
            {
                if(temp[i]>mid)
                {
                    temp[i-1]+=temp[i]-mid;
                }
            }
            if(temp[0]>mid)
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};