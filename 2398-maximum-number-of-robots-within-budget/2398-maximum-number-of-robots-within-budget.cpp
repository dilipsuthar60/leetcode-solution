class Solution
{
    public:
        long long n;
    int find(vector<int> &ch, vector<int> &run, int k, long long bud)
    {
        deque<int> q;
        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            while (q.size() && ch[q.back()] < ch[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            sum += run[i];
        }
        int xt = 0;
        long long max_val = ch[q.front()];
        if (max_val + k * sum <= bud)
        {
            return true;
        }
        for (int i = k; i < n; i++)
        {
            if (q.front() == i - k)
            {
                q.pop_front();
            }
            while (q.size() && ch[q.back()] < ch[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            sum -= run[i - k];
            sum += run[i];
            max_val = ch[q.front()];
            if (max_val + k * sum <= bud)
            {
                return true;
            }
        }
        return false;
    }
    int maximumRobots(vector<int> &charge, vector<int> &run, long long bud)
    {
        n = charge.size();
        long long l = 1;
        long long r = n;
        int ans = 0;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            if (find(charge, run, mid, bud))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};