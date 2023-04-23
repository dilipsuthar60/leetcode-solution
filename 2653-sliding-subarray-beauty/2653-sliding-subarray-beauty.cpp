class Solution {
public:
    int bit[500];
    void update(int i,int val)
    {
        i++;
        while(i<500)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int find(int i)
    {
        i++;
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    int kth(int k)
    {
        int ans=0;
        int l=0,r=100;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(mid)>k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        ans=ans-50;
        return ans>0?0:ans;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) 
    {
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            update(nums[i]+50,1);
        }
        vector<int>v;
        v.push_back(kth(x-1));
        for(int i=k;i<n;i++)
        {
            update(nums[i-k]+50,-1);
            update(nums[i]+50,1);
            v.push_back(kth(x-1));
        }
        return v;
    }
};