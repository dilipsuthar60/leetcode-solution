class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>v1,v2;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                v1.push_back(nums[i]);
            }
            else
            {
                v2.push_back(nums[i]);
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int>());
        vector<int>ans(n,0);
        int l=0;
        for(int i=0;i<v1.size();i++)
        {
            ans[l]=v1[i];
            l+=2;
        }
        l=1;
        for(int i=0;i<v2.size();i++)
        {
            ans[l]=v2[i];
            l+=2;
        }
        return ans;
    }
};