class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int n=nums.size();
        multiset<int>mp;
        mp.insert(nums[0]);
        int j=0;
        for(int i=1;i<n;i++)
        {
            if(mp.size()>k)
            {
                mp.erase(mp.find(nums[j++]));
            }
            nums[i]=nums[i]+*mp.rbegin();
            mp.insert(nums[i]);
        }
        return nums.back();
    }
};