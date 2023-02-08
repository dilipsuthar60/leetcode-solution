class Solution
{
    public:
        int maxNumberOfFamilies(int n, vector<vector < int>> &nums)
        {
            unordered_map<int, int> dp;
            for (auto &it: nums)
            {
                int numberOfRow = it[0];
                int position= it[1];
                dp[numberOfRow] |= (1 << (position - 1));
            }
            int ans = 2 *(n - dp.size());
            for (auto &[numberOfRow, postion]: dp)
            {
                if (!(postion&(0b0111111110)))
                {
                    ans += 2;
                }
                else
                {
                    if (!(postion&(0b0111100000)) || !(postion&(0b0001111000)) || !(postion&(0b0000011110)))
                    {
                        ans++;
                    }
                }
            }
            return ans;
        }
};