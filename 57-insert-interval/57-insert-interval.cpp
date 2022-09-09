class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        nums.push_back(newInterval);
        int n=nums.size();
        if(n==0)
        {
            return {};
        }
        int j=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[j][1]>=nums[i][0])
            {
                nums[j][1]=max({nums[j][1],nums[i][1]});
            }
            else
            {
                nums[++j]=nums[i];
            }
        }
        return vector<vector<int>>(nums.begin(),nums.begin()+j+1);
    }
};
// [[1,2],[3,10],[12,16]]