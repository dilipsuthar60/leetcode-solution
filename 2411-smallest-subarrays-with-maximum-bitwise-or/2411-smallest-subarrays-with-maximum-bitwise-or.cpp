class Solution {
public:
    int N=1e5+10;
    int bit[100005];
    void update(int i,int val)
    {
        i++;
        while(i<N)
        {
            bit[i]|=val;
            i+=(i&-i);
        }
    }
    int find(int i)
    {
        i++;
        int sum=0;
        while(i>0)
        {
            sum|=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans(n,0);
        int total=0;
        for(int i=n-1;i>=0;i--)
        {
            total|=nums[i];
            update(i,nums[i]);
            int l=i;
            int r=n-1;
            int index=n-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(find(mid)==total)
                {
                    index=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            ans[i]=(index-i+1);
        }
        return ans;
    }
};