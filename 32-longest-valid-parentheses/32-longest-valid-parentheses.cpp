class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>stack;
        int n=s.size();
        vector<int>nums(n,0);
        int stack_count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stack_count++;
                stack.push_back(i);
            }
            else if(stack_count)
            {
                nums[i]=1;
                nums[stack.back()]=1;
                stack.pop_back();
                stack_count--;
            }
        }
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                count++;
            }
            else
            {
                count=0;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};