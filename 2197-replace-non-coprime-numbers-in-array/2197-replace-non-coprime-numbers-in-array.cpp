class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(nums[i]);
            while(ans.size()>1&&(__gcd(ans.back(),ans[ans.size()-2]))>1)
            {
                long long g=(1ll*ans.back()*ans[ans.size()-2])/__gcd(ans.back()+0ll,ans[ans.size()-2]+0ll);
                ans.pop_back();
                ans.pop_back();
                ans.push_back(g);
            }
        }
        return ans;
    }
};