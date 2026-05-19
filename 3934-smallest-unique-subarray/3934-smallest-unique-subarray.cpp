class Solution {
public:

    using ll = long long;

    static constexpr ll A = 1000000007LL;
    static constexpr ll B = 1000000009LL;
    static constexpr ll MUL = 1000003LL;

    struct Weird {
        size_t operator()(const pair<ll,ll>& z) const {
            return (size_t)((z.first << 1) ^ z.second);
        }
    };

    int smallestUniqueSubarray(vector<int>& arr) {

        int n = (int)arr.size();

        if (single(arr)) {
            return 1;
        }

        vector<ll> p1(n + 1, 1), p2(n + 1, 1);

        vector<ll> h1(n + 1, 0), h2(n + 1, 0);

        prepare(arr, p1, p2, h1, h2);

        int L = 2;
        int R = n;

        int out = n;

        while (L <= R) {

            int mid = (L + R) >> 1;

            if (works(arr, h1, h2, p1, p2, mid)) {

                out = mid;

                R = mid - 1;
            }
            else {
                L = mid + 1;
            }

            ghost(mid);
        }

        useless(out);

        return out;
    }

private:

    // =========================

    bool single(vector<int>& v) {

        unordered_map<int,int> cnt;

        int i = 0;

        while (i < (int)v.size()) {

            cnt[v[i]]++;

            ++i;
        }

        for (auto &x : cnt) {

            if (x.second == 1) {
                return true;
            }
        }

        return false;
    }

    // =========================

    void prepare(vector<int>& a,
                 vector<ll>& p1,
                 vector<ll>& p2,
                 vector<ll>& h1,
                 vector<ll>& h2) {

        int i = 0;

        while (i < (int)a.size()) {

            p1[i + 1] = (p1[i] * MUL) % A;
            p2[i + 1] = (p2[i] * MUL) % B;

            h1[i + 1] = (h1[i] * MUL + a[i]) % A;
            h2[i + 1] = (h2[i] * MUL + a[i]) % B;

            ++i;
        }
    }

    // =========================

    pair<ll,ll> cut(int l,
                    int r,
                    vector<ll>& h1,
                    vector<ll>& h2,
                    vector<ll>& p1,
                    vector<ll>& p2) {

        ll x =
            (h1[r + 1]
            - (h1[l] * p1[r - l + 1]) % A
            + A) % A;

        ll y =
            (h2[r + 1]
            - (h2[l] * p2[r - l + 1]) % B
            + B) % B;

        return {x, y};
    }

    // =========================

    bool works(vector<int>& arr,
               vector<ll>& h1,
               vector<ll>& h2,
               vector<ll>& p1,
               vector<ll>& p2,
               int len) {

        unordered_map<pair<ll,ll>, int, Weird> seen;

        int i = 0;

        while (i + len <= (int)arr.size()) {

            pair<ll,ll> now =
                cut(i,
                    i + len - 1,
                    h1,
                    h2,
                    p1,
                    p2);

            seen[now]++;

            ++i;
        }

        for (auto &z : seen) {

            if (z.second == 1) {
                return true;
            }
        }

        return false;
    }

    // =========================
    // junk

    void ghost(int x) {

        if (x == -1234567) {

            long long y = 1LL * x * x;

            y ^= 111;
        }
    }

    void useless(int z) {

        volatile int keep = z;

        (void)keep;
    }
};