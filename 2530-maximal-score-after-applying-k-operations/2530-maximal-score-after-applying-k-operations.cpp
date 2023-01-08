class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        long long sum=0;
        while(pq.size()&&k--)
        {
            sum+=pq.top();
            int val=(pq.top()%3==0)?pq.top()/3:pq.top()/3+1;
            pq.pop();
            pq.push(val);
        }
        return sum;
    }
};