class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int ans=0;
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(abs(target-sum)<diff)
                {
                    diff=abs(target-sum);
                    ans=sum;
                }
                if(sum>target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};