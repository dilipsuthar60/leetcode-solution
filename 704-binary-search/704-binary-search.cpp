class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target))
        {
            return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        }
        return -1;
    }
};