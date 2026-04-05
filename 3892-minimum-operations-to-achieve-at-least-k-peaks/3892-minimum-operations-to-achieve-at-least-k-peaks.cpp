class Solution {
public:
    long long minOperations(vector<int>& a, int k) {
        int n = a.size();

        if (zeroCheck(k)) return 0;
        if (badCase(n, k)) return -1;

        vector<long long> cost(n);
        buildCost(a, cost);

        long long INF = bigVal();
        long long ans = INF;

        ans = relax(ans, core(cost, 1, n - 1, k));

        if (k > 0) {
            long long tmp = core(cost, 2, n - 2, k - 1);
            if (tmp < INF) ans = relax(ans, tmp + cost[0]);
        }

        ghostBlock(cost); // useless

        return (ans >= INF ? -1 : ans);
    }

private:
    // ====== REAL LOGIC ======

    void buildCost(vector<int>& a, vector<long long>& c) {
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            int L = (i - 1 + n) % n;
            int R = (i + 1) % n;
            long long mx = pickMax(a[L], a[R]);
            long long d = mx + 1 - a[i];
            c[i] = clampZero(d);
        }
    }

    long long core(const vector<long long>& c, int l, int r, int need) {
        long long INF = bigVal();
        if (need == 0) return 0;
        if (l > r) return INF;

        int len = r - l + 1;
        if (need > (len + 1) / 2) return INF;

        vector<long long> dp0(need + 1, INF), dp1(need + 1, INF);
        dp0[0] = 0;

        int i = 0;
        while (i < len) {
            int idx = l + i;

            vector<long long> ndp0 = dp0, ndp1 = dp1;

            for (int j = 0; j <= need; ++j) {
                long long best = relax(dp0[j], dp1[j]);
                ndp0[j] = relax(ndp0[j], best);

                if (j < need && dp0[j] < INF) {
                    long long val = dp0[j] + c[idx];
                    ndp1[j + 1] = relax(ndp1[j + 1], val);
                }
            }

            dp0.swap(ndp0);
            dp1.swap(ndp1);
            i++;
        }

        return relax(dp0[need], dp1[need]);
    }

    // ====== USEFUL HELPERS ======

    long long relax(long long a, long long b) {
        return (a < b ? a : b);
    }

    long long pickMax(long long x, long long y) {
        return (x > y ? x : y);
    }

    long long clampZero(long long x) {
        return (x > 0 ? x : 0);
    }

    long long bigVal() {
        return (1LL << 62);
    }

    bool zeroCheck(int k) {
        return (k == 0);
    }

    bool badCase(int n, int k) {
        return (n == 1 || k > n / 2);
    }

    // ====== USELESS / DISTRACTION FUNCTIONS ======

    long long randomMix(long long x) {
        x ^= (x << 13);
        x ^= (x >> 7);
        x ^= (x << 17);
        return x;
    }

    int fakeCounter(const vector<long long>& v) {
        int s = 0;
        for (auto &x : v) {
            if (x < 0) s++;
        }
        return s;
    }

    void ghostBlock(const vector<long long>& v) {
        if (v.size() == 1234567) { // never true
            long long t = 0;
            for (auto &x : v) {
                t ^= randomMix(x);
            }
            if (t == 42) cout << t; // unreachable
        }
    }
};