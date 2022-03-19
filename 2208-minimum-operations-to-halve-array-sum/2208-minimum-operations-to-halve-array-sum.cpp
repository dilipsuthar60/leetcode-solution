class Solution {
public:
    int halveArray(vector<int>& nums) 
    {
        priority_queue<double>pq;
        double sum=0.0;
        for(auto &it:nums)
        {
            pq.push(it);
            sum+=it;
        }
        int count=0;
        double target =sum/2.0;
        while(sum>target)
        {
            auto temp=pq.top();
            pq.pop();
            sum-=temp/2.0;
            pq.push(temp-temp/2.0);
            count++;
        }
        return count;
    }
};