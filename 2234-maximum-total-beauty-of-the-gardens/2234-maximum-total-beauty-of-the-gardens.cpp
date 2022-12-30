class Solution {
public:
    int n;
    long long maximumBeauty(vector<int>&flower, long long newflower, int target, int full, int partial) 
    {
        n=flower.size();
        sort(flower.begin(),flower.end());
        vector<long long>prefix(n,0);
        prefix[0]=flower[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+flower[i];
        }
        auto find=[&](int bs)
        {
            int l=0;
            int r=target-1;
            long long ans=0;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                auto it=upper_bound(flower.begin(),flower.begin()+bs,mid);
                if(it==flower.begin())
                {
                    l=mid+1;
                    continue;
                }
                long long index=it-flower.begin();
                if((mid*index-prefix[index-1])<=newflower)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            return ans;
        };
        long long ans=1ll*find(n)*partial;
        int bs_index=n;
        for(int i=n-1;i>=0;i--)
        {
            newflower-=max(0ll,0ll+target-flower[i]);
            if(newflower<0)
            {
                break;
            }
            bs_index--;
            ans=max(ans,1ll*full*(n-i)+1ll*find(bs_index)*partial);
        }
        return ans;
    }
};
