class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) 
    {
        int dp1[10]={0};
        int dp2[10]={0};
        for(auto it:nums1)
        {
            dp1[it]++;
        }
        for(auto it:nums2)
        {
            dp1[it]++;
        }
        for(int i=1;i<=9;i++)
        {
            if(dp1[i]>=2)
            {
                return i;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        return min(nums1.front(),nums2.front())*10+max(nums1.front(),nums2.front());
    }
};