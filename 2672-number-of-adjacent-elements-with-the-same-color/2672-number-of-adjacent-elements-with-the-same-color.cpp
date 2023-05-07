class Solution
{
    public:
        vector<int> colorTheArray(int n, vector<vector < int>> &q)
        {
            vector<int> v;
            vector<int> nums(n);
            int count = 0;
            for (auto it: q)
            {
                int index = it[0];
                int col = it[1];
                if (nums[index])
                {
                    if (index - 1 >= 0 && nums[index - 1] == nums[index])
                    {
                        count--;
                    }
                    if (index + 1 < n && nums[index + 1] == nums[index])
                    {
                        count--;
                    }
                }
                nums[index] = col;
                if (index - 1 >= 0 && nums[index - 1] == col)
                {
                    count++;
                }
                if (index + 1 < n && nums[index + 1] == col)
                {
                    count++;
                }
                v.push_back(count);
            }
            return v;
        }
};