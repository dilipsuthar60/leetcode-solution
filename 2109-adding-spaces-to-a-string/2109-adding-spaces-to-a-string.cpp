class Solution {
public:
    string addSpaces(string s, vector<int>& nums) {
        string ans="";
        int l=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(l<nums.size()&&i==nums[l])
            {
                ans+=" ";
                l++;
            }
            ans+=s[i];
        }
        return ans;
    }
};