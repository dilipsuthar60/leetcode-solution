class Solution {
public:
    int chalkReplacer(vector<int>& nums, int k) 
    {
        long long  n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),1ll*0);
        long long   val=k%sum;
        long long index=0;
        long long  i=0;
        while(true)
        {
            int sum=nums[i%n];
            if(val>=sum)
            {
                i++;
                val=val-sum;
            }
            else
            {
                index=i;
                break;
            }
        }
        return (int)index;
    }
};