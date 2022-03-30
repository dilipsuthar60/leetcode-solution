class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        int count1=0;
        int count2=0;
        vector<vector<int>>ans(2);
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(),nums2.end());
        for(auto it:s1)
        {
            if(s2.find(it)==s2.end())
            {
                ans[0].push_back(it);
            }
        }
        for(auto it:s2)
        {
            if(s1.find(it)==s1.end())
            {
                ans[1].push_back(it);
            }
        }
     return ans;
    }
};