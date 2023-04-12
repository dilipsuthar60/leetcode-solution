class Solution {
public:

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n=nums1.size();
        vector<pair<long long,long long>>nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back({nums2[i],nums1[i]});
        }
        long long ans=0;
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n;i++)
        {
            sum+=nums[i].second;
            pq.push(nums[i].second);
            if(pq.size()==k)
            {
                ans=max(ans,sum*nums[i].first);
                sum-=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};