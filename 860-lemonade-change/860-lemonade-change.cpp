class Solution {
public:
    bool lemonadeChange(vector<int>& nums) 
    {
        int n=nums.size();
        int no5=0;
        int no10=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==5)
            {
                no5++;
            }
            else if(nums[i]==10)
            {
                if(no5)
                {
                    no5--;
                }
                else
                {
                    return false;
                }
                no10++;
            }
            else
            {
                if(no5&&no10)
                {
                    no5--;
                    no10--;
                }
                else if(no5>=3)
                {
                    no5-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};