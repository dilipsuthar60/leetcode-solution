class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int n=nums.size();
        int one=count(nums.begin(),nums.end(),1);
        // for(int i=0;i<n;i++)
        // {
        //     nums.push_back(nums[i]);
        // }
        int max_one=0;
        int curr_one=0;
        for(int i=0;i<2*n;i++)
        {
            if(i>=one&&nums[(i-one)%n]==1)
            {
                curr_one--;
            }
            if(nums[i%n]==1)
            {
                curr_one++;
            }
            max_one=max(max_one,curr_one);
        }
        return one-max_one;
    }
};