class Solution {
public:
    int validSubarraySize(vector<int>& nums, int val) 
    {
        int n=nums.size();
        vector<int>left(n,-1),right(n,n);
        vector<int>stack;
        for(int i=0;i<n;i++)
        {
            while(stack.size()&&nums[stack.back()]>=nums[i])
            {
                stack.pop_back();
            }
            if(stack.size())
            {
                left[i]=stack.back();
            }
            stack.push_back(i);
        }
        stack.clear();
        for(int i=n-1;i>=0;i--)
        {
            while(stack.size()&&nums[stack.back()]>=nums[i])
            {
                stack.pop_back();
            }
            if(stack.size())
            {
                right[i]=stack.back();
            }
            stack.push_back(i);
        }
//         for(int i=0;i<n;i++)
//         {
//             cout<<left[i]<<" ";
//         }
//         cout<<endl;
        
//         for(int i=0;i<n;i++)
//         {
//             cout<<right[i]<<" ";
//         }
//         cout<<endl;
        for(int i=0;i<n;i++)
        {
            int len=right[i]-left[i]-1;
            if(1ll*nums[i]*len>val)
            {
                return len;
            }
        }
        return -1;
    }
};