class Solution {
public:
    long long find(vector<int>&nums,int min_val,int max_val)
    {
        int n=nums.size();
        int min_index=-1;
        int max_index=-1;
        long long ans=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            // if(nums[i]>max_val||nums[i]<min_val)
            // {
            //     min_index=-1;
            //     max_index=-1;
            // }
            if(nums[i]==min_val)
            {
                min_index=i;
            }
            if(nums[i]==max_val)
            {
                max_index=i;
            }
            if(min_index!=-1&&max_index!=-1)
            {
                ans+=min(min_index,max_index)+1;
            }
        }
        return ans;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        vector<vector<int>>v;
        vector<int>curr;
        for(int i=0;i<nums.size();i++)
        {
             if(nums[i]>maxK||nums[i]<minK)
            {
                if(curr.size())
                {
                    v.push_back(curr);
                    curr.clear();
                }
            }
            else
            {
                curr.push_back(nums[i]);
            }
        }
        if(curr.size())
        {
            v.push_back(curr);
        }
        long long ans=0;
        for(auto it:v)
        {
            ans+=find(it,minK,maxK);
        }
        return ans;
    }
};