class Solution {
public:
    int n;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) 
    {
        n=nums1.size();
        int target=k1+k2;
        vector<long long>nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back(abs(nums1[i]-nums2[i]));
        }
        sort(nums.begin(),nums.end(),greater<int>());
        long long l=0;
        long long r=1e9;
        long long ans=-1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=max(0ll,nums[i]-mid);
            }
            if(sum<=target)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        long long result=0;
        for(int i=0;i<n;i++)
        {
            target-=max(0ll,nums[i]-ans);
            nums[i]=min(nums[i],ans);
        }
        for(int i=0;i<min(target,n);i++)
        {
            if(nums[i])
            nums[i]--;
        }
        for(int i=0;i<n;i++)
        {
            result+=(nums[i]*nums[i]);
        }
        return result;
    }
};