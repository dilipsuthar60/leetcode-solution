class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue<long long ,vector<long long>,greater<long long>>pq;
        for(auto &it:nums)
        {
            pq.push(it);
        }
        while(k--&&pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            temp++;
            pq.push(temp);
        }
        int mod=1e9+7;
        long long ans=1;
        while(pq.size())
        {
            ans=(ans*pq.top())%mod;
            pq.pop();
        }
        return (int)ans%mod;
    }
};