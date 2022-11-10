class Solution {
public:
    void find(vector<int>&nums,int index,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(index==nums.size())
        {
            ans.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=-11)
            {
                int curr_value=nums[i];
                curr.push_back(nums[i]);
                nums[i]=-11;
                find(nums,index+1,curr,ans);
                curr.pop_back();
                nums[i]=curr_value;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>result;
        find(nums,0,ans,result);
        return result;
    }
};