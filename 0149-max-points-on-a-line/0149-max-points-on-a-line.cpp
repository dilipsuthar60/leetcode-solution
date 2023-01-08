class Solution
{
    public:
        int maxPoints(vector<vector < int>> &points)
        {
            int n = points.size();
            if (n <= 2) return n;
            int ans = 0;

            for (auto it1: points)
            {
                unordered_map<double, int> mp;
                double x1 = it1[0], y1 = it1[1];
                for (auto it2: points)
                {
                    if (it2 == it1) continue;
                    double x2 = it2[0], y2 = it2[1];
                    double slope;
                    slope = (y2 - y1) / (x2 - x1);
                    mp[slope]++;
                    ans = max(ans, mp[slope]);
                }
            }
            return ans + 1;
        }
};