class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        vector<int> p(n), sz(n, 1), xr(n, 0);
        for (int i = 0; i < n; ++i)
            p[i] = i;

        auto climb = [&](int v, int& acc) {
            acc = 0;
            int cur = v;

            while (p[cur] != cur) {
                acc ^= xr[cur];
                cur = p[cur];
            }

            int root = cur;
            cur = v;
            int carry = 0;

            while (p[cur] != cur) {
                int nxt = p[cur];
                int old = xr[cur];
                xr[cur] = acc ^ carry;
                carry ^= old;
                p[cur] = root;
                cur = nxt;
            }

            return root;
        };

        int kept = 0;
        for (auto& e : edges) {
            int a = e[0], b = e[1], val = e[2];
            int xa = 0, xb = 0;
            int ra = climb(a, xa);
            int rb = climb(b, xb);

            if (ra == rb) {
                if ((xa ^ xb) == val) {
                    kept++;
                }
                continue;
            }
            if (sz[ra] < sz[rb]) {
                swap(ra, rb);
                swap(xa, xb);
            }
            p[rb] = ra;
            xr[rb] = xa ^ xb ^ val;
            sz[ra] += sz[rb];
            kept++;
        }
        return kept;
    }
};