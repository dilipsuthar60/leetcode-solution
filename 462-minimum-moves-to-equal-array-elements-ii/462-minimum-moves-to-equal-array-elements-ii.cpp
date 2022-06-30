class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=nums[nums.size()/2];
        int count=0;
        for(auto &it:nums)
        {
            count+=abs(it-mid);
        }
        return count;
   }
};