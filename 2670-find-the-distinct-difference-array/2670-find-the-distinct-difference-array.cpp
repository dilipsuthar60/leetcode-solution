class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>right,left;
        for(auto it:nums)
        {
            right[it]++;
        }
        for(auto it:nums)
        {
            left[it]++;
            right[it]--;
            if(right[it]==0)
            {
                right.erase(it);
            }
            ans.push_back(left.size()-right.size());
        }
        return ans;
    }
};