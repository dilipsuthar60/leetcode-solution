class Solution {
public:
    int countHousePlacements(int n) 
    {
        int mod=1e9+7;
        long long os=1;
        long long ob=1;
        for(int i=2;i<=n;i++)
        {
            long long nb=os%mod;
            long long ns=(os+ob)%mod;
            ob=nb;
            os=ns;
        }
        return (((os+ob)%mod)*((os+ob)%mod))%mod;
    }
};