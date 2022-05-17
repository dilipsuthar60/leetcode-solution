class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>&nums, int len) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>sum(n);
        for(int i=0;i<n;i++)
        {
            sum[i]=nums[i][1]-nums[i][0]+1;
            if(i)
            {
                sum[i]+=sum[i-1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int st=nums[i][0];
            int ed=nums[i][1];
            int req=st+len-1;
            int l=i;
            int r=n-1;
            int index=i;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(nums[mid][0]<=req)
                {
                    l=mid+1;
                    index=mid;
                }
                else
                {
                    r=mid-1;
                }
            }
            int tile=sum[index];
            if(i)
            {
                tile-=sum[i-1];
            }
            if(nums[index][1]>req)
            {
                tile-=(nums[index][1]-req);
            }
            ans=max(ans,tile);
        }
        return ans;
    }
};