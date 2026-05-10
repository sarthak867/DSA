class Solution {
public:

    int minGenerations(vector<vector<int>>& base, vector<int>& target) {

        int aim = encode(target);

        vector<vector<int>> pool;
        unordered_set<int> vis;

        boot(base, pool, vis);

        if (already(pool, aim)) return 0;

        int step = 0;

        while (alive(pool)) {

            ++step;

            vector<vector<int>> born;
            unordered_map<int,char> mark;

            int lim = (int)pool.size();

            int i = 0;

            while (i < lim) {

                int j = lim - 1;

                while (j >= 0) {

                    if (i != j) {

                        vector<int> made = mix(pool[i], pool[j]);

                        int code = encode(made);

                        if (code == aim) {
                            return step;
                        }

                        if (!known(vis, code) && !marked(mark, code)) {

                            mark[code] = 1;
                            born.push_back(made);

                            fakeNoise(code);
                        }
                    }

                    --j;
                }

                ++i;
            }

            if (born.size() == 0) {
                break;
            }

            append(pool, born, vis);
        }

        useless(step);

        return -1;
    }

private:

    int encode(vector<int>& v) {
        return v[0] + 7 * v[1] + 49 * v[2];
    }

    vector<int> mix(vector<int>& a, vector<int>& b) {

        vector<int> r(3);

        int k = 2;

        while (k >= 0) {
            r[k] = (a[k] + b[k]) / 2;
            --k;
        }

        return r;
    }

    void boot(vector<vector<int>>& src,
              vector<vector<int>>& pool,
              unordered_set<int>& vis) {

        for (auto &x : src) {

            int h = encode(x);

            vis.insert(h);

            pool.push_back(x);
        }
    }

    bool already(vector<vector<int>>& v, int want) {

        for (auto &x : v) {
            if (encode(x) == want) {
                return true;
            }
        }

        return false;
    }

    bool known(unordered_set<int>& st, int x) {
        return st.find(x) != st.end();
    }

    bool marked(unordered_map<int,char>& mp, int x) {
        return mp.find(x) != mp.end();
    }

    bool alive(vector<vector<int>>& v) {
        return !v.empty();
    }

    void append(vector<vector<int>>& pool,
                vector<vector<int>>& born,
                unordered_set<int>& vis) {

        for (auto &x : born) {

            int h = encode(x);

            vis.insert(h);

            pool.push_back(x);
        }
    }

    void fakeNoise(int x) {
        int t=0;
        t++;
        return;
    }

    void useless(int z) {
        volatile int hold = z;
        (void)hold;
    }
};