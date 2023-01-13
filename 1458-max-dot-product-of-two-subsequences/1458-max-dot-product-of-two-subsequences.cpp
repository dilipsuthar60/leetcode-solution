class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&nums1,vector<int>&nums2,int index1,int index2)
    {
        if(index1==nums1.size()||index2==nums2.size())
        {
            return -1e7;
        }
        if(dp[index1][index2]!=-1e9)
        {
            return dp[index1][index2];
        }
        int curr=nums1[index1]*nums2[index2];
        return dp[index1][index2]=max({curr,curr+find(nums1,nums2,index1+1,index2+1),find(nums1,nums2,index1+1,index2),find(nums1,nums2,index1,index2+1)});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        dp=vector<vector<int>>(nums1.size()+1,vector<int>(nums2.size()+1,-1e9));
        return find(nums1,nums2,0,0);
    }
};