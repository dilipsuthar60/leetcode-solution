class Solution {
public:
    bool doesValidArrayExist(vector<int>&nums) 
    {
        int sum=0;
        for(auto it:nums)
        {
            sum^=it;
        }
        return sum==0;
    }
};