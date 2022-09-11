class Solution {
public:
    int maxPerformance(int n,vector<int>&speed,vector<int>& eff,int k) 
    {
        vector<pair<int,int>>nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back({eff[i],speed[i]});
        }
        int mod=1e9+7;
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(nums.rbegin(),nums.rend());
        long long  ans=0;
        for(auto &[e,s]:nums)
        {
            sum+=s;
            pq.push(s);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
                
            }
            ans=max(ans,sum*e);
        }
        return ans%mod;
    }
};