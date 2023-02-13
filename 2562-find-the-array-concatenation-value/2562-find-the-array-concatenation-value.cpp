class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        vector<string>v;
        int n=nums.size();
        for(int i=0;i<n/2;i++)
        {
            v.push_back(to_string(nums[i])+to_string(nums[n-1-i]));
        }
        if(n&1)
        {
            v.push_back(to_string(nums[n/2]));
        }
        long long ans=0;
        for(auto it:v)
        {
            ans+=stoi(it);
        }
        return ans;
    }
};