class Solution {
public:
    const int mx=300005+10;
    int bit[300005+10];
    void update(int i,int val)
    {
        while(i<mx)
        {
            bit[i]+=val;
            i=i+(i&-i);
        }
    }
    int find(int i)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i=i-(i&-i);
        }
        return sum;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff)
    {    
        int n=nums1.size();
        long long count=0;
        for(int i=0;i<n;i++)
        {
            count+=find(nums1[i]-nums2[i]+diff+80000);
            update(nums1[i]-nums2[i]+80000,1);
        }
        return count;
    }
};