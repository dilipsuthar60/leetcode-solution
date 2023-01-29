class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        long long max,min;
        int n=nums.size();
            max=min=nums[0]+nums[n-1];
            priority_queue<int> q1;
            priority_queue<int, vector<int>, greater<int>> q2;
            for(int i=0;i<n-1;i++){
                q1.push(nums[i]+nums[i+1]);
                q2.push(nums[i]+nums[i+1]);
            }
            for(int i=0;i<k-1;i++){
                max+=q1.top();q1.pop();
                min+=q2.top();q2.pop();
            }
            return max-min;
    }
};