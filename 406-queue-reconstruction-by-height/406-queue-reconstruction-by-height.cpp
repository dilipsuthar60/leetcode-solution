class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>&nums)
    {
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];});
        vector<vector<int>>ans;
        for(auto &it:nums)
        {
            ans.insert(ans.begin()+it[1],it);
        }
        return ans;
    }
};