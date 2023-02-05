class Solution {
public:
    long long pickGifts(vector<int>& nums, int k) 
    {
        priority_queue<long long>pq(nums.begin(),nums.end());
        while(k--)
        {
            long long val=pq.top();
            pq.pop();
            pq.push(sqrt(val));
        }
        long long sum=0;
        while(pq.size())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};