class Solution {
public:
    int minCost(string s, vector<int>&nums) 
    {
        int cost=0;
        int n=s.size();
        vector<pair<char,int>>stack;
        for(int i=0;i<n;i++)
        {
            if(stack.size()&&stack.back().first==s[i])
            {
                if(nums[i]>stack.back().second)
                {
                    cost+=stack.back().second;
                    stack.pop_back();
                    stack.push_back({s[i],nums[i]});
                }
                else
                {
                    cost+=nums[i];
                }
            }
            else
            {
                stack.push_back({s[i],nums[i]});
            }
        }
        return cost;
    }
};