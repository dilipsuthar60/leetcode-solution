class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int n=nums.size();
        vector<int>v1,v2,v3;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            {
                v1.push_back(nums[i]);
            }
            if(nums[i]==pivot)
            {
                v2.push_back(nums[i]);
            }
            if(nums[i]>pivot)
            {
                v3.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(auto &it:v1)
        {
            ans.push_back(it);
        }
        for(auto &it:v2)
        {
            ans.push_back(it);
        }
        for(auto &it:v3)
        {
            ans.push_back(it);
        }
        return ans;
    }
};