class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int last=nums.back();
        int sum=0;
        while(k--)
        {
            sum+=last;
            last++;
        }
        return sum;
    }
};