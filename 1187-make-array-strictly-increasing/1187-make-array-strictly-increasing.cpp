class Solution {
public:
    int n;
    int yes;
    map<int,int>mp[2001];
    int find(vector<int>&nums,int index,int prev,vector<int>&arr)
    {
        if(index==n)
        {
            yes=1;
            return 0;
        }
        if(mp[index].find(prev)!=mp[index].end())
        {
            return mp[index][prev];
        }
        int j=upper_bound(arr.begin(),arr.end(),prev)-arr.begin();
        int ans=1e8;
        if(prev<nums[index])
        {
            ans=min(ans,find(nums,index+1,nums[index],arr));
        }
        if(j<arr.size())
        {
            ans=min(ans,1+find(nums,index+1,arr[j],arr));
        }
        return mp[index][prev]=ans;
        
    }
    int makeArrayIncreasing(vector<int>&nums, vector<int>& arr) 
    {
        yes=0;
        n=nums.size();
        sort(arr.begin(),arr.end()); 
        int val=find(nums,0,-1,arr);
        if(yes)
        {
            return val;
        }
        return -1;
    }
};