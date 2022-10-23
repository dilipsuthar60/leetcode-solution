class Solution {
public:
    //   int res = 0;
    // unordered_map<int, int> gcds;
    // for (int i = 0; i < nums.size(); ++i) {
    //     unordered_map<int, int> gcds1;
    //     if (nums[i] % k == 0) {
    //         ++gcds[nums[i]];
    //         for (auto [prev_gcd, cnt] : gcds)
    //             gcds1[gcd(prev_gcd, nums[i])] += cnt;
    //     }
    //     res += gcds1[k];
    //     swap(gcds, gcds1);
    // }
    // return res;
    int subarrayGCD(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        unordered_map<int,int>dp1;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>dp2;
            // if(nums[i]%k==0)
            // {
                dp1[nums[i]]++;
                for(auto &[a,b]:dp1)
                {
                    dp2[__gcd(nums[i],a)]+=b;
                }
            // }
            count+=dp2[k];
            dp1.swap(dp2);
        }
        return count;
    }
};