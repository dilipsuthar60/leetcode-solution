class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        set<int>s;
        vector<int>ans;
        int n=nums.size();
        vector<int>array;
        for(int i=0;i<n;i++)
        {
            if(array.size()==0||array.back()<=nums[i])
            {
                array.push_back(nums[i]);
                ans.push_back(array.size());
            }
            else
            {
                auto index=upper_bound(array.begin(),array.end(),nums[i])-array.begin();
                array[index]=nums[i];
                ans.push_back(index+1);
            }
        }
        return ans;
    }
};