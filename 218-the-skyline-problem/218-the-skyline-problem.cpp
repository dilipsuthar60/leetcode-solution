class Solution
{
    public:
        vector<vector < int>> getSkyline(vector<vector < int>> &nums)
        {
            int n;
            vector<vector < int>> v;
            for (auto it: nums)
            {
                v.push_back({ it[0],
                    -it[2] });
                v.push_back({ it[1],
                    it[2] });
            }
            sort(v.begin(), v.end());
            multiset<int> m;
            vector<vector < int>> ans;
            m.insert(0);
            n = v.size();
            int prev, curr;
            prev = curr = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i][1] < 0)
                {
                    m.insert(-v[i][1]);
                }
                else
                {
                    m.erase(m.find(v[i][1]));
                }
                curr = *m.rbegin();
                if (curr != prev)
                {
                    ans.push_back({ v[i][0],
                        curr });
                    prev = curr;
                }
            }
            return ans;
        }
};