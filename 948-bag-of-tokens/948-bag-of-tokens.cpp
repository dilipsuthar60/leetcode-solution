class Solution {
public:
    int bagOfTokensScore(vector<int>&nums, int pow) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        int ans=0;
        for(int i=0,j=n-1;i<=j;)
        {
            if(nums[i]<=pow)
            {
                pow-=nums[i++];
                count++;
                ans=max(ans,count);
            }
            else if(count>0)
            {
                pow+=nums[j];
                j--;
                count--;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};