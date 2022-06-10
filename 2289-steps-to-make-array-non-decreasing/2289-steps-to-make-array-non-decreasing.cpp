class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        stack<pair<int,int>>s;
        int time=0;
        s.push({nums[n-1],0});
        for(int i=n-2;~i;i--)
        {
            time=0;
            while(s.size()&&s.top().first<nums[i])
            {
                time=max(time+1,s.top().second);
                s.pop();
            }
            ans=max(ans,time);
            s.push({nums[i],time});
        }
        return ans;
    }
};