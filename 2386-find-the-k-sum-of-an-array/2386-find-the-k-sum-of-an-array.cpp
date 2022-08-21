class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>ans;
        priority_queue<pair<long long,long long>>pq;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                sum+=nums[i];
            }
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        pq.push({sum-nums[0],0});
        ans.push_back(sum);
        while(ans.size()<k)
        {
            auto [val,index]=pq.top();
            pq.pop();
            ans.push_back(val);
            if(index+1<n)
            {
                pq.push({val+nums[index]-nums[index+1],index+1});
                pq.push({val-nums[index+1],index+1});
            }
        }
        return ans[k-1];
    }
};