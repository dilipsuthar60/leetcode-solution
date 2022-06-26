class Solution {
public:
    int find(vector<int>&nums1,vector<int>&nums2)
    {
        int sum=accumulate(nums1.begin(),nums1.end(),0);
        int s=0;
        int a=0;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            s=max(nums2[i]-nums1[i],s+nums2[i]-nums1[i]);
            a=max(s,a);
        }
        return sum+a;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) 
    {
        return max(find(nums1,nums2),find(nums2,nums1));
    }
};