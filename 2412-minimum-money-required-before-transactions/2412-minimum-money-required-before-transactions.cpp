class Solution {
public:
    bool find(vector<vector<int>>&p,vector<vector<int>>&l,long long mid)
    {
        for(int i=0;i<l.size();i++)
        {
            if(mid<l[i][0])
            {
                return false;
            }
            mid=mid-l[i][0]+l[i][1];
        }
        for(int i=0;i<p.size();i++)
        {
            if(mid<p[i][0])
            {
                return false;
            }
            mid=mid-p[i][0]+p[i][1];
        }
        return true;
    }
    long long minimumMoney(vector<vector<int>>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>p,l;
        for(const auto &it:nums)
        {
            if(it[1]>=it[0])
            {
                p.push_back(it);
            }
            else
            {
                l.push_back(it);
            }
        }
        sort(p.begin(),p.end(),[&](auto &a,auto &b){return a[0]>b[0];});
        sort(l.begin(),l.end(),[&](auto &a,auto &b){return (a[1]==b[1])?a[0]>b[0]:a[1]<b[1];});
        long long x=0;
        long long y=1e15;
        long long ans=0;
        while(x<=y)
        {
            long long mid=(x+y)/2;
            if(find(p,l,mid))
            {
                ans=mid;
                y=mid-1;
            }
            else
            {
                x=mid+1;
            }
        }
        return ans;
    }
};
