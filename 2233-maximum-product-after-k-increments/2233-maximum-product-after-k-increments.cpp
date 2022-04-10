class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(n==1)
        {
            return nums[0]+k;
        }
        priority_queue<long long ,vector<long long>,greater<long long>>pq;
        for(auto &it:nums)
        {
            pq.push(it);
        }
        while(k)
        {
            auto temp1=pq.top();
            pq.pop();
            auto temp2=pq.top();
            pq.pop();
            int diff=min(k+0ll,(temp2-temp1+1));
            k-=diff;
            temp1+=diff;
            pq.push(temp1);
            pq.push(temp2);
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