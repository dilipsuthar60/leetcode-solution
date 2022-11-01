class Solution {
public:
    vector<int>findl(vector<int>&nums)
    {
        int n=nums.size();
        stack<int>s;
        vector<int>left(n,-1);
        for(int i=0;i<n;i++)
        {
            while(s.size()&&nums[i]<=nums[s.top()])
            {
                s.pop();
            }
            if(s.size())
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
        stack<int>s;
        vector<int>right(n,n);
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()&&nums[i]<=nums[s.top()])
            {
                s.pop();
            }
            if(s.size())
            {
                right[i]=s.top();
            }
            s.push(i);
        }
        return right;
    }
    int validSubarraySize(vector<int>& nums, int threshold) 
    {
        int n=nums.size();
        vector<int>left=findl(nums);
        vector<int>right=findr(nums);
        for(int i=0;i<n;i++)
        {
            // cout<<left[i]<<" "<<right[i]<<endl;
            int len=(right[i]-left[i]-1);
            if(1ll*nums[i]*len>threshold)
            {
                return len;
            }
        }
        return -1;
    }
};