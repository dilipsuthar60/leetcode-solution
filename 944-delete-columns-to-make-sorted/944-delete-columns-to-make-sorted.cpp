class Solution {
public:
    int minDeletionSize(vector<string>& nums) 
    {
        int count=0;
        int n=nums.size();
        int m=nums[0].size();
        for(int j=0;j<m;j++)
        {
            string s="";
            for(int i=0;i<n;i++)
            {
                s.push_back(nums[i][j]);
            }
            if(!is_sorted(s.begin(),s.end()))
            {
                count++;
            }
        }
        return count;
    }
};