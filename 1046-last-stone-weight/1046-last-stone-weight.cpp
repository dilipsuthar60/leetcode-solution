class Solution {
public:
    int lastStoneWeight(vector<int>& nums) 
    {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(pq.size()>1)
        {
            int m1,m2;
            m1=pq.top();
            pq.pop();
            m2=pq.top();
            pq.pop();
            if(m1>m2)
            pq.push(m1-m2);
        }
        return pq.empty()?0:pq.top();
    }
};