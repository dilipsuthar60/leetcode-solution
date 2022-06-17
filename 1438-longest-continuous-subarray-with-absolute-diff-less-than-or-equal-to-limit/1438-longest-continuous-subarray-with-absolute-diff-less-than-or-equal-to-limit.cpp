class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)    
    {
        int j=0;
        int len=0;
        deque<int>mx,mn;
        for(int i=0,n=nums.size();i<n;i++)
        {
            while(mx.size()&&mx.back()<nums[i])
            {
                mx.pop_back();
            }
            while(mn.size()&&mn.back()>nums[i])
            {
                mn.pop_back();
            }
            mx.push_back(nums[i]);
            mn.push_back(nums[i]);
            while(mx.front()-mn.front()>limit)
            {
                if(mx.front()==nums[j])
                {
                    mx.pop_front();
                }
                if(mn.front()==nums[j])
                {
                    mn.pop_front();
                }
                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};