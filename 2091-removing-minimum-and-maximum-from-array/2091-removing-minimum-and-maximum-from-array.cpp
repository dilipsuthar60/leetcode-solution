class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int i=min_element(nums.begin(),nums.end())-nums.begin();
        int j=max_element(nums.begin(),nums.end())-nums.begin();
        int n=nums.size();
        int case1=max(i+1,j+1);
        int case2=max(n-i,n-j);
        int case3=i+1+n-j;
        int case4=j+1+n-i;
        return min({case1,case2,case3,case4});
    }
};