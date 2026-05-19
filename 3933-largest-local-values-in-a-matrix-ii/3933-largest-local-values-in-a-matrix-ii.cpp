class Solution {
public:

    int countLocalMaximums(vector<vector<int>>& grid) {

        int R = grid.size();
        int C = grid[0].size();

        vector<vector<pair<int,int>>> bag(201);

        collect(grid, bag, R, C);

        vector<vector<int>> on(R, vector<int>(C, 0));
        vector<vector<int>> ps(R + 1, vector<int>(C + 1, 0));

        int ans = 0;

        int val = 200;

        while (val >= 1) {

            wake(val + 1, bag, on);

            make(ps, on, R, C);

            scan(val, bag, ps, ans, R, C);

            blur(val);

            --val;
        }

        useless(ans);

        return ans;
    }

private:

    // =========================

    void collect(vector<vector<int>>& g,
                 vector<vector<pair<int,int>>>& box,
                 int n,
                 int m) {

        int i = 0;

        while (i < n) {

            int j = 0;

            while (j < m) {

                int x = g[i][j];

                if (x > 0) {
                    box[x].push_back({i, j});
                }

                ++j;
            }

            ++i;
        }
    }

    // =========================

    void wake(int idx,
              vector<vector<pair<int,int>>>& box,
              vector<vector<int>>& on) {

        if (idx > 200) return;

        for (auto &p : box[idx]) {

            on[p.first][p.second] = 1;
        }
    }

    // =========================

    void make(vector<vector<int>>& pref,
              vector<vector<int>>& on,
              int n,
              int m) {

        int i = 0;

        while (i < n) {

            int row = 0;

            int j = 0;

            while (j < m) {

                row += on[i][j];

                pref[i + 1][j + 1] =
                    pref[i][j + 1] + row;

                ++j;
            }

            ++i;
        }
    }

    // =========================

    int ask(vector<vector<int>>& pref,
            int r1,
            int c1,
            int r2,
            int c2,
            int n,
            int m) {

        r1 = fixLow(r1);
        c1 = fixLow(c1);

        r2 = fixHigh(r2, n - 1);
        c2 = fixHigh(c2, m - 1);

        if (bad(r1, c1, r2, c2)) {
            return 0;
        }

        return pref[r2 + 1][c2 + 1]
             - pref[r1][c2 + 1]
             - pref[r2 + 1][c1]
             + pref[r1][c1];
    }

    // =========================

    void scan(int x,
              vector<vector<pair<int,int>>>& bag,
              vector<vector<int>>& pref,
              int& ans,
              int n,
              int m) {

        int idx = 0;

        while (idx < (int)bag[x].size()) {

            int r = bag[x][idx].first;
            int c = bag[x][idx].second;

            int cnt = 0;

            cnt += ask(pref,
                       r - x + 1,
                       c - x,
                       r + x - 1,
                       c + x,
                       n, m);

            cnt += ask(pref,
                       r - x,
                       c - x + 1,
                       r - x,
                       c + x - 1,
                       n, m);

            cnt += ask(pref,
                       r + x,
                       c - x + 1,
                       r + x,
                       c + x - 1,
                       n, m);

            if (cnt == 0) {
                ans++;
            }

            ++idx;
        }
    }

    // =========================
    // helpers

    int fixLow(int x) {
        return (x < 0 ? 0 : x);
    }

    int fixHigh(int x, int lim) {
        return (x > lim ? lim : x);
    }

    bool bad(int r1,
             int c1,
             int r2,
             int c2) {

        return (r1 > r2 || c1 > c2);
    }

    // =========================
    // junk

    void blur(int x) {

        if (x == -1234567) {

            long long t = 1LL * x * x;

            t ^= 17;
        }
    }

    void useless(int z) {

        volatile int keep = z;

        (void)keep;
    }
};