class MKAverage {
public:
    int m, k;
    deque<int> dq;
    long sum[100003], cnt[100003];
    MKAverage(int m, int k) {
        memset(sum, 0, sizeof(sum));
        this->m = m, this->k = k;
    }
    void update(int num, int val) {
        int u = val / num;
        num += 1;
        while (num < 100002) {
            cnt[num] += u;
            sum[num] += val;
            num += num & -num;
        }
    }
    long get(long BIT[],int x) {
        long res = 0;
        x += 1;
        while (x) {
            res += BIT[x];
            x -= x & -x;
        }
        return res;
    }
    void addElement(int num) {
        dq.push_back(num);
        update(num, num);
        if (dq.size() > m) {
            update(dq.front(), -dq.front());
            dq.pop_front();
        }
    }
    int searchIndex(int kk) { // binary search
        int low = 0, high = 1e5 + 1;
        while (low < high) {
            int mid = high + low >> 1;
            if (get(cnt, mid) < kk) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    int calculateMKAverage() {
        if (dq.size() < m)
            return -1;
        int low = searchIndex(k);
        int high = searchIndex(m - k);
        long ans = get(sum, high) - get(sum, low);
        ans += (get(cnt, low) - k) * low;
        ans -= (get(cnt, high) - (m - k)) * high;
        return ans / (m - 2 * k);
    }
};