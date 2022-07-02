class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>&nums)
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=houses.size();
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(nums.begin(),nums.end(),houses[i]);
            int curr=INT_MAX;
            if(it!=nums.end())
            {
                curr=*it-houses[i];
            }
            if(it!=nums.begin())
            {
                it--;
                curr=min(curr,houses[i]-*it);
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};