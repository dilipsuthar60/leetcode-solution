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
            if(nums[mid]==k)
            {
                return mid;
            }
            if(nums[mid]<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l;
    }
    vector<int> findClosestElements(vector<int>&nums, int k, int x) 
    {
        int index=find(nums,x);
        int l=index-1;
        int r=index;
        vector<int>ans;
        int n=nums.size();
        while(l>=0&&r<n&&k)
        {
            if(abs(nums[l]-x)<=abs(nums[r]-x))
            {
                ans.push_back(nums[l]);
                l--;
            }
            else
            {
                ans.push_back(nums[r]);
                r++;
            }
            k--;
        }
        while(l>=0&&k)
        {
            ans.push_back(nums[l--]);
            k--;
        }
         while(r<n&&k)
        {
            ans.push_back(nums[r++]);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};