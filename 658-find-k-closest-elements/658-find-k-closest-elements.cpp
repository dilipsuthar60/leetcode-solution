class Solution {
public:
    int find(vector<int>&nums,int k)
    {
        int mid=0;
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
             mid=(l+r)>>1;
            // if(nums[mid]==k)
            // {
            //     return mid;
            // }
            if(nums[mid]<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return r;
    }
    vector<int> findClosestElements(vector<int>&nums, int k, int x) 
    {
        int index=find(nums,x);
        int l=index;
        int r=index+1;
        vector<int>ans;
        int n=nums.size();
        while(l>=0&&r<n&&k)
        {
            if(abs(nums[l]-x)<=abs(nums[r]-x))
            {
                l--;
            }
            else
            {
                r++;
            }
            k--;
        }
        while(l>=0&&k)
        {
            l--;
            k--;
        }
         while(r<n&&k)
        {
            r++;
            k--;
        }
        return vector<int>(nums.begin()+l+1,nums.begin()+r);
    }
};