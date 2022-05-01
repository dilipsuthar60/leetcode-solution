class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        
        long long right=accumulate(nums.begin(),nums.end(),0ll);
        int index=0;
        long long left=0;
        long long val=INT_MAX;
        for(int i=0,n=nums.size();i<n;i++)
        {
            left+=nums[i];
            right-=nums[i];
            long long d1=(left/(i+1));
            long long d2=0;
            if(n-i-1)
            {
                d2=(right/(n-i-1));
            }
            long long diff=abs(d1-d2);
            if(diff<val)
            {
                val=diff;
                index=i;
            }
        }
        return index;
    }
};