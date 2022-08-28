class Solution {
public:
    int find(vector<int>&nums,int val)
    {
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]<=val)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) 
    {
        sort(nums.begin(),nums.end());
        for(int i=1,n=nums.size();i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        vector<int>ans;
        for(auto it:q)
        {
            int index=find(nums,it);
            ans.push_back(index);
        }
        return ans;
    }
};