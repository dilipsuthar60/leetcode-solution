class Solution {
public:
    vector<int> addToArrayForm(vector<int>&nums, int k)
    {
        int n=nums.size();
        for(int i=n-1;i>=0&&k;i--)
        {
            nums[i]+=k;
            k=nums[i]/10;
            nums[i]=nums[i]%10;
        }
        while(k)
        {
            nums.insert(nums.begin(),k%10);
            k/=10;
        }
        return nums;
    }
};