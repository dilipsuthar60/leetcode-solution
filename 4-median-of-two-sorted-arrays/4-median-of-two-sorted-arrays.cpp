class Solution {
public:
    int lesser(vector<int>&nums1,vector<int>&nums2,int k)
    {
        int first=upper_bound(nums1.begin(),nums1.end(),k)-nums1.begin();
        int second=upper_bound(nums2.begin(),nums2.end(),k)-nums2.begin();
        return first+second;
    }
    int find(vector<int>&nums1,vector<int>&nums2,int k)
    {
        int l=-1e9;
        int r=1e9;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(lesser(nums1,nums2,mid)>=k)
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        if(total==0)
        {
            return 0.0;
        }
        double left=find(nums1,nums2,total/2);
        double right=find(nums1,nums2,total/2+1);
        if(total%2==1)
        {
            return right;
        }
        return double(left/2.0+right/2.0);
    }
};