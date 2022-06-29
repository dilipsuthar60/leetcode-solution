class Solution {
public:
     int N=2e3+100;
    vector<int>bit;
    void update(int i,int val)
    {
        i++;
        while(i<N)
        {
            bit[i]+=val;
            i+=(i&-i);
        }
    }
    int find(int i)
    {
        int sum=0;
        i++;
        while(i>0)
        {
            sum+=bit[i];
            i-=(i&-i);
        }
        return sum;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>&nums)
    {
        bit.resize(N);
        int n=nums.size();
        sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];});
        for(auto it:nums)
        {
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        vector<vector<int>>ans(n);
        for(int i=1;i<n;i++)
        {
            update(i,1);
        }
        for(int i=0;i<n;i++)
        {
            int l=0;
            int r=n-1;
            int index=0;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(find(mid)>=nums[i][1])
                {
                    index=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            ans[index]=nums[i];
            update(index,-1);
        }
        return ans;
    }
};