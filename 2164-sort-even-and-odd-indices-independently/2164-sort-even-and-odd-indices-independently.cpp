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
        int i=0;
        int j=0;
        while(i<v1.size()||j<v2.size())
        {
            if(i<v1.size())
            {
                ans[l++]=v1[i++];
            }
            if(j<v2.size())
            {
                ans[l++]=v2[j++];
            }
        }
        return ans;
    }
};