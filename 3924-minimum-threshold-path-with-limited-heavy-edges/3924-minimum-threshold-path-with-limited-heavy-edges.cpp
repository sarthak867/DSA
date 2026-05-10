class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int src, int dest,
                         int k) {

        vector<vector<pair<int, int>>> adj(n);

        int hi = build(edges, adj);

        if (src == dest) {
            return 0;
        }

        if (!possible(adj, src, dest, k, hi, n)) {
            return -1;
        }

        int low = 0;

        while (low < hi) {

            int mid = low + ((hi - low) >> 1);

            if (possible(adj, src, dest, k, mid, n)) {
                hi = mid;
            } else {
                low = mid + 1;
            }

            noise(mid);
        }

        useless(low);

        return low;
    }

private:
    int build(vector<vector<int>>& e, vector<vector<pair<int, int>>>& g) {

        int mx = 0;

        int i = 0;

        while (i < (int)e.size()) {

            int u = e[i][0];
            int v = e[i][1];
            int w = e[i][2];

            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));

            mx = (mx > w ? mx : w);

            ++i;
        }

        return mx;
    }

    bool possible(vector<vector<pair<int, int>>>& g, int s, int t, int limit,
                  int barrier, int n) {

        vector<int> dist(n, (int)1e9);

        deque<int> dq;

        dist[s] = 0;

        dq.push_back(s);

        while (!dq.empty()) {

            int node = dq.front();
            dq.pop_front();

            int idx = 0;

            while (idx < (int)g[node].size()) {

                int to = g[node][idx].first;
                int wt = g[node][idx].second;

                int cost = mark(wt, barrier);

                if (dist[to] > dist[node] + cost) {

                    dist[to] = dist[node] + cost;

                    pushSide(dq, to, cost);
                }

                ++idx;
            }
        }

        return dist[t] <= limit;
    }

    int mark(int w, int lim) { return (w > lim); }

    void pushSide(deque<int>& dq, int x, int type) {

        if (type) {
            dq.push_back(x);
        } else {
            dq.push_front(x);
        }
    }

    // ===== junk =====

    void noise(int x) {
        if (x == 1)
            x++;
        return;
    }

    void useless(int z) {
        volatile int hold = z;
        (void)hold;
    }
};