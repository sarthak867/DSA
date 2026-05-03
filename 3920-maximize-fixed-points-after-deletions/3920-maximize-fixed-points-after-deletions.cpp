class Solution {
    struct BIT {
        vector<int> tree;

        BIT(int n) {
            tree.assign(n + 2, 0);
        }

        void update(int idx, int val) {
            idx++;
            while (idx < tree.size()) {
                tree[idx] = max(tree[idx], val);
                idx += idx & -idx;
            }
        }

        int getMax(int idx) {
            idx++;
            int ans = 0;
            while (idx > 0) {
                ans = max(ans, tree[idx]);
                idx -= idx & -idx;
            }
            return ans;
        }
    };

public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> valid;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= i) {
                int value = nums[i];
                int gap = i - nums[i];
                valid.push_back({value, gap});
            }
        }

        sort(valid.begin(), valid.end());

        BIT bit(n);
        int ans = 0;

        int i = 0;
        while (i < valid.size()) {
            int value = valid[i].first;
            vector<pair<int, int>> updates;

            while (i < valid.size() && valid[i].first == value) {
                int gap = valid[i].second;

                int bestBefore = bit.getMax(gap);
                int curr = bestBefore + 1;

                updates.push_back({gap, curr});
                ans = max(ans, curr);

                i++;
            }

            for (auto& it : updates) {
                bit.update(it.first, it.second);
            }
        }

        return ans;
    }
};
