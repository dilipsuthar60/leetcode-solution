class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        int ans=0;
        int mod=1e9+7;
        unordered_map<int,int>mp;
        for(int i=0,n=arr.size();i<n;i++)
        {
            ans=(ans+mp[target-arr[i]])%mod;
            for(int j=0;j<i;j++)
            {
                mp[arr[i]+arr[j]]++;
            }
        }
        return ans;
    }
};