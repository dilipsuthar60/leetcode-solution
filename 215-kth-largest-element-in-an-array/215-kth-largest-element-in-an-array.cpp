class Solution {
public:
    int partition(vector<int>&nums,int val,int lo,int hi)
    {
        int i=lo;
        int j=lo;
        int n=nums.size();
        while(i<=hi)
        {
            if(nums[i]>val)
            {
                i++;
            }
            else
            {
                swap(nums[i++],nums[j++]);
            }
        }
        return j-1;
    }
    int  find(vector<int>&nums,int lo,int hi, int k)
    {
        
        int index=partition(nums,nums[hi],lo,hi);
        if(index<k)
        {
          return find(nums,index+1,hi,k);
        }
        else if(index>k)
        {
           return find(nums,lo,index-1,k);
        }
     
        return nums[index];
    }
    int findKthLargest(vector<int>& nums, int k)
    {
      return find(nums,0,nums.size()-1,nums.size()-k);
    }
};