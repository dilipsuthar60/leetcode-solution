class Solution
{
    public:
        int matchPlayersAndTrainers(vector<int> &p, vector<int> &t)
        {
            sort(p.begin(), p.end());
            sort(t.begin(), t.end());
            int ans = 0;
            for (int i = 0, j = 0; i < p.size(); i++)
            {
                while (j < t.size() && t[j] < p[i])
                {
                    j++;
                }
                if (j == t.size())
                {
                    break;
                }
                if (j < t.size())
                {
                    j++;
                    ans++;
                }
            }
            return ans;
        }
};