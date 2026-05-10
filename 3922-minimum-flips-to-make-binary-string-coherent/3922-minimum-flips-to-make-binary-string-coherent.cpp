class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int o = 0;
        for (char c : s) {
            if (c == '1')
                o++;
        }

        int z = n - o;

        int res = 1e9;

        // keep at most one '1'
        res = min(res, max(0, o - 1));

        // make all characters '1'
        res = min(res, z);

        // make pattern like 1000...0001
        if (n > 1) {
            int cur = 0;

            if (s[0] != '1')
                cur++;
            if (s[n - 1] != '1')
                cur++;

            for (int i = 1; i < n - 1; i++) {
                if (s[i] == '1')
                    cur++;
            }

            res = min(res, cur);
        }

        return res;
    }
};