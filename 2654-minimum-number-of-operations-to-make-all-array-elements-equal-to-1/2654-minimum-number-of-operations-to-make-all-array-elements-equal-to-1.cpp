class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n=nums.size();
        int one=0;
        for(int i=0;i<n;i++)
        {
            one+=(nums[i]==1);
        }
        if(one)
        {
            return n-one;
        }
        int min_dis=1e9;
        for(int i=0;i<n;i++)
        {
            int gcd=nums[i];
            for(int j=i+1;j<n;j++)
            {
                gcd=__gcd(gcd,nums[j]);
                if(gcd==1)
                {
                    min_dis=min(min_dis,j-i);
                }
            }
        }
        if(min_dis==1e9)
        {
            return -1;
        }
        return n+min_dis-1;
    }
};