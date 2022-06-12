class Solution {
public:
    int n;
    bool find(vector<int>&nums,int k,int mid)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mid<nums[i])
            {
                return false;
            }
            if(sum>mid)
            {
                count++;
                sum=nums[i];
            }
        }
        return count<=k;
    }
    int bs(vector<int>&nums,int k)
    {
        int l=0;
        int ans=0;
        int r=1e6;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,k,mid))
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
    int distributeCookies(vector<int>& nums, int k) 
    {
        n=nums.size();
        int ans=1e8;
        sort(nums.begin(),nums.end());
        do
        {
         ans=min(ans,bs(nums,k));   
        }while(next_permutation(nums.begin(),nums.end()));
       
        return ans;
    }
};