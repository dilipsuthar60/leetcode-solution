class Solution {
public:
    int find(vector<int>&nums)
    {
        int n=nums.size();
        int max_sum=0;
        int curr_sum=0;
        for(int i=0;i<n;i++)
        {
            curr_sum=max(curr_sum+nums[i],nums[i]);
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) 
    {
        unordered_map<char,int>mp;
        for(int i=0,n=chars.size();i<n;i++)
        {
            mp[chars[i]]=vals[i];
        }
        vector<int>nums(s.size(),0);
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                nums[i]=mp[s[i]];
            }
            else
            {
                nums[i]=(s[i]-'a'+1);
            }
        }
        return find(nums);
    }
};