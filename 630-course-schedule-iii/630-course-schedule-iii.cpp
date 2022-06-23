class Solution {
public:
    int scheduleCourse(vector<vector<int>>&nums) 
    {
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a[1]<b[1];});
        priority_queue<int>pq;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i][0];
            pq.push(nums[i][0]);
            if(sum>nums[i][1])
            {
                sum-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};