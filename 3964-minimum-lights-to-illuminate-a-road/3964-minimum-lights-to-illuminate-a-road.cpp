class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        map<int, int> dark;

        int cskip = 0;
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                cskip = max(0, cskip - 1);
                cskip = max(cskip, lights[i]);
            } else if (cskip > 0) {
                cskip--;
            } else {
                dark[i]++;
            }
        }

        cskip = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (lights[i] > 0) {
                cskip = max(0, cskip - 1);
                cskip = max(cskip, lights[i]);
            } else if (cskip > 0) {
                cskip--;
            } else {
                dark[i]++;
            }
        }

        int req = 0;
        bool skip = 0, dskip = 0;

        for (auto [a, b] : dark) {
            if (skip) {
                skip = 0;
                continue;
            }
            if (dskip) {
                dskip = 0;
                continue;
            }

            if (b == 2) {
                if (dark.count(a + 1) && dark[a + 1] == 2)
                    skip = 1;
                if (skip && dark.count(a + 2) && dark[a + 2] == 2)
                    dskip = 1;
                req++;
            }
        }

        return req;
    }
};