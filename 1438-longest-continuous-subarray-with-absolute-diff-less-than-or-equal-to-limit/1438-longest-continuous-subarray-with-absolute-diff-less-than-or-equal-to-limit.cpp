class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n=nums.size();
        multiset<int>s;
        int len=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
            while(*s.rbegin()-*s.begin()>limit)
            {
                s.erase(s.find(nums[j]));
                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};