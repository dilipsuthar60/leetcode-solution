class Solution {
public:
    const int N=1e5+5;
    vector<int>bitl,bitr;
    void update(int i,int val,vector<int>&bit)
    {
        while(i<N)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int find(int i,vector<int>&bit)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    int find_(int i,vector<int>&bit)
    {
        return find(N-2,bit)-find(i-1,bit);
    }
    int numTeams(vector<int>& nums) 
    {
        bitl.resize(N);
        bitr.resize(N);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            update(nums[i],1,bitr);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            update(nums[i],-1,bitr);
            int left_small=find(nums[i]-1,bitl);
            int right_big=find_(nums[i]+1,bitr);
            int left_big=find_(nums[i]+1,bitl);
            int right_small=find(nums[i]-1,bitr);
            count+=left_small*right_big+left_big*right_small;
            update(nums[i],1,bitl);
        }
        return count;
    }
};