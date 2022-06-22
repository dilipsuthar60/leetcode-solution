class Solution {
public:
    vector<int>findl(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>left(n,0);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(s.size()&&nums[s.top()]>=nums[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                left[i]=-1;
            }
            else
            {
                left[i]=s.top();
            }
            s.push(i);
        }
        return left;
    }
    vector<int>findr(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>right(n,0);
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()&&nums[s.top()]>=nums[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                right[i]=n;
            }
            else
            {
                right[i]=s.top();
            }
            s.push(i);
        }
        return right;
    }
    int maximumScore(vector<int>& nums, int k) 
    {
        int ans=0;
        vector<int>left=findl(nums);
        vector<int>right=findr(nums);
        int score=0;
        for(int i=0;i<nums.size();i++)
        {
            int l=left[i];
            int r=right[i];
            if(l+1<=k && r-1>=k)
            {
                score=max(score,nums[i]*(r-l-1));
            }
        }
        return score;
    }
};