class Solution {
public:
    double average(vector<int>& nums) {
        double a=*max_element(nums.begin(),nums.end());
        double b=*min_element(nums.begin(),nums.end());
        double sum=accumulate(nums.begin(),nums.end(),0);
        return double((sum-a-b)/(0.0+double(nums.size())-2.0));
    }
};