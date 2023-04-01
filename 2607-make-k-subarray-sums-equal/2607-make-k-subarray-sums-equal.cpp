class Solution {
public:
    long long find(vector<int>&nums)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long cost=0;
        for(int i=0;i<n;i++)
        {
            cost+=abs(nums[n/2]-nums[i]);
        }
        return cost;
    }
    long long makeSubKSumEqual(vector<int>&nums, int k) 
    {
        int n=nums.size();
        long long cost=0;
        vector<int>vis(n,0);
        for(int i=0;i<k;i++)
        {
            vector<int>v;
            int j=i;
            while(!vis[j])
            {
                vis[j]=1;
                v.push_back(nums[j]);
                j=(j+k)%n;
            }
            cost+=find(v);
        }
        return cost;
    }
};