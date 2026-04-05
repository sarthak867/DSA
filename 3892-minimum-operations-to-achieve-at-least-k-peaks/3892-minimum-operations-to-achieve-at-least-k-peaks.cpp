class Solution {
public:
    long long minOperations(vector<int>& a, int k) {
        int n = a.size();

        if (k == 0) return 0;
        if (n == 1 || k > n / 2) return -1;

        vector<long long> c(n);
        prep(a, c);

        long long INF = BIG();
        long long ans = INF;

        ans = better(ans, solve(c, 1, n - 1, k));

        if (k > 0) {
            long long t = solve(c, 2, n - 2, k - 1);
            if (t < INF) ans = better(ans, t + c[0]);
        }

        dummy(c); // useless

        return (ans >= INF ? -1 : ans);
    }

private:
    void prep(vector<int>& a, vector<long long>& c) {
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            int L = (i - 1 + n) % n;
            int R = (i + 1) % n;
            long long mx = (a[L] > a[R] ? a[L] : a[R]);
            long long d = mx + 1 - a[i];
            c[i] = (d > 0 ? d : 0);
        }
    }

    long long solve(const vector<long long>& c, int l, int r, int need) {
        long long INF = BIG();

        if (need == 0) return 0;
        if (l > r) return INF;

        int len = r - l + 1;
        if (need > (len + 1) / 2) return INF;

        vector<long long> dp0(need + 1, INF), dp1(need + 1, INF);
        dp0[0] = 0;

        for (int i = 0; i < len; ++i) {
            int idx = l + i;

            // reverse loop → overwrite safe
            for (int j = need; j >= 0; --j) {

                long long best = better(dp0[j], dp1[j]);
                dp0[j] = better(dp0[j], best);

                if (j > 0 && dp0[j - 1] < INF) {
                    long long val = dp0[j - 1] + c[idx];
                    dp1[j] = better(dp1[j], val);
                }
            }
        }

        return better(dp0[need], dp1[need]);
    }

    long long better(long long a, long long b) {
        return (a < b ? a : b);
    }

    long long BIG() {
        return (1LL << 62);
    }

    // useless block (safe)
    void dummy(const vector<long long>& v) {
        if (v.size() == 123456789) {
            long long x = 0;
            for (auto &y : v) x ^= y;
            if (x == 42) cout << x;
        }
    }
};