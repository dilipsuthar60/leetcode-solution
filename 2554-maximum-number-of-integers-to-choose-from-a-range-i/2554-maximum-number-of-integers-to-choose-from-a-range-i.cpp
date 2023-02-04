class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int hash[10005];
        memset(hash,0,sizeof(hash));
        long long sum=0;
        for(auto it:banned)
        {
            hash[it]++;
        }
        int count=0;
        for(int i=1;i<=n&&sum+i<=maxSum;i++)
        {
            if(hash[i])
            {
                continue;
            }
            sum+=i;
            count++;
        }
        return count;
    }
};