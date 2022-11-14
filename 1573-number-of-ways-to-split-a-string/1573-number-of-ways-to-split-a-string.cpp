class Solution
{
    public:
        int numWays(string s)
        {
            int n = s.size();
            int zero = count(s.begin(), s.end(), '0');
            int one = n - zero;
            int mod = 1e9 + 7;
            int first_way = 0;
            int second_way = 0;
            int target = one / 3;
            int count = 0;
            if (one == 0)
            {
                return (1ll *(n - 1) *(n - 2) / 2) % mod;
            }
            if (one % 3)
            {
                return 0;
            }
            for (int i = 0; i < n; i++)
            {
                count += (s[i] - '0');
                if (count == target)
                {
                    first_way++;
                }
                else if (count == 2 *target)
                {
                    second_way++;
                }
            }
            return (1ll*first_way * 1ll*second_way) % mod;
        }
};