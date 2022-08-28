class Solution {
public:
    const int N=1e5+10;
    int bit[100005+10];
    int find(int i)
    {
        int sum=0;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    void update(int i,int val)
    {
        while(i<N)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-k+1;i++)
        {
            int point=nums[i]+find(i+1);
            if(point%2==0)
            {
                count++;
                update(i+1,1);
                update(i+1+k,-1);
            }
        }
        for(int i=0;i<n;i++)
        {
            int point=nums[i]+find(i+1);
            if(point%2==0)
            {
                return -1;
            }
        }
        return count;
    }
};