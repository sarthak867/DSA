class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums2.size();
        int B = 320;
        int blocks = (n + B - 1) / B;

        vector<long long> a(nums2.begin(), nums2.end());
        vector<long long> lazy(blocks, 0);
        vector<unordered_map<long long, int>> freq(blocks);

        auto rebuild = [&](int b) {
            freq[b].clear();

            int l = b * B;
            int r = min(n, l + B);

            for (int i = l; i < r; i++) {
                freq[b][a[i]]++;
            }
        };

        auto push = [&](int b) {
            if (lazy[b] == 0) return;

            int l = b * B;
            int r = min(n, l + B);

            for (int i = l; i < r; i++) {
                a[i] += lazy[b];
            }

            lazy[b] = 0;
            rebuild(b);
        };

        for (int b = 0; b < blocks; b++) {
            rebuild(b);
        }

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int l = q[1];
                int r = q[2];
                int val = q[3];

                int bl = l / B;
                int br = r / B;

                if (bl == br) {
                    push(bl);

                    for (int i = l; i <= r; i++) {
                        a[i] += val;
                    }

                    rebuild(bl);
                } else {
                    push(bl);
                    int endLeft = min(n - 1, (bl + 1) * B - 1);
                    for (int i = l; i <= endLeft; i++) {
                        a[i] += val;
                    }
                    rebuild(bl);

                    for (int b = bl + 1; b < br; b++) {
                        lazy[b] += val;
                    }

                    push(br);
                    int startRight = br * B;
                    for (int i = startRight; i <= r; i++) {
                        a[i] += val;
                    }
                    rebuild(br);
                }
            } else {
                int tot = q[1];
                int cnt = 0;

                for (int x : nums1) {
                    long long need = tot - x;

                    for (int b = 0; b < blocks; b++) {
                        cnt += freq[b][need - lazy[b]];
                    }
                }

                ans.push_back(cnt);
            }
        }

        return ans;
    }
};