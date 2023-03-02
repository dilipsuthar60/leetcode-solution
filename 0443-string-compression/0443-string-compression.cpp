class Solution {
public:
    int compress(vector<char>& nums) 
    {
        int n=nums.size();
        int j=0;
        int i=0;
        while(i<n)
        {
            int count=0;
            char ch=nums[i];
            while(i<n&&ch==nums[i])
            {
                count++;
                i++;
            }
            nums[j++]=ch;
            if(count>1)
            {
                string str=to_string(count);
                for(auto it:str)
                {
                    nums[j++]=it;
                }
            }
        }
        return j;
    }
};