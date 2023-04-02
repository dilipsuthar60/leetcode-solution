class Solution {
public:
    int miceAndCheese(vector<int>&nums1, vector<int>&nums2, int k) 
    {
        int n=nums1.size();
        int total=accumulate(nums2.begin(),nums2.end(),0);
        vector<int>diff(n);
        for(int i=0;i<n;i++)
        {
            diff[i]=nums1[i]-nums2[i];
        }
        sort(diff.rbegin(),diff.rend());
        for(int i=0;i<k;i++)
        {
            total+=diff[i];
        }
        return total;
    }
};