class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                v.push_back(nums[i]);
            }
            else if(nums[i]!=nums[i-1])
            {
                v.push_back(nums[i]);
            }
        }
        int count=0;
        for(int i=1;i<v.size()-1;i++)
        {
            count+=(v[i-1]<v[i]&&v[i]>v[i+1]);
            count+=(v[i-1]>v[i]&&v[i]<v[i+1]);
        }
        return count;
    }
};