
// int n = nums.size();
        
//         vector<int> t(n, 0);
//         t = nums;
//         priority_queue<P, vector<P>> pq;
//         pq.push({t[0], 0});
        
//         int maxR = t[0];
        
//         for(int i = 1; i<n; i++) {
            
//             while(!pq.empty() && pq.top().second < i - k)
//                 pq.pop();
            
//             t[i] = max(t[i], nums[i] + pq.top().first);
//             pq.push({t[i], i});
            
//             maxR = max(maxR, t[i]);
//         }
        
        
//         return maxR;
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        multiset<pair<int,int>,greater<pair<int,int>>>mp;
        mp.insert({nums[0],0});
        vector<int>dp(n,0);
        dp=nums;
        for(int i=1;i<n;i++)
        {
            while(mp.size()&&(i-(*mp.begin()).second)>k)
            {
                mp.erase(mp.begin());
            }
            dp[i]=max(dp[i],nums[i]+(*mp.begin()).first);
            mp.insert({dp[i],i});
        }
        return *max_element(dp.begin(),dp.end());
        // deque<int>dq;
        // for(int i=0;i<n;i++)
        // {
        //     if(dq.size()&&k<i-dq.front())
        //     {
        //         dq.pop_front();
        //     }
        //     if(dq.size())
        //     {
        //         nums[i]=max(nums[i],nums[i]+nums[dq.front()]);
        //     }
        //     while(dq.size()&&nums[dq.back()]<nums[i])
        //     {
        //         dq.pop_back();
        //     }
        //     dq.push_back(i);
        // }
        // return *max_element(nums.begin(),nums.end());
    }
};