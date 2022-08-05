class Solution {
public:
    bool find(vector<int>&nums,int *sum,int index,int mid,int k)
    {
        if(index>nums.size())
        {
            return false;
        }
        if(index==nums.size())
        {
            return true;
        }
        for(int i=0;i<k;i++)
        {
            sum[i]+=nums[index];
            if(sum[i]<=mid&&find(nums,sum,index+1,mid,k))
            {
                return true;
            }
            sum[i]-=nums[index];
            if(sum[i]==0)
            {
                return false;
            }
        }
        return false;
    }
    int minimumTimeRequired(vector<int>&nums, int k) 
    {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        sort(nums.begin(),nums.end());
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int sum[k];
            memset(sum,0,sizeof(sum));
            if(find(nums,sum,0,mid,k))   
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