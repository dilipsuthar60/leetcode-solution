class Solution {
public:
    int maxEvents(vector<vector<int>>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        int day=0;
        int count=0;
        while(pq.size()||i<n)
        {
            if(pq.size()==0)
            {
                day=nums[i][0];
            }
            while(i<n&&nums[i][0]==day)
            {
                pq.push(nums[i++][1]);
            }
            count++;
            day++;
            pq.pop();
            while(pq.size()&&pq.top()<day)
            {
                pq.pop();
            }
        }
        return count;
    }
};