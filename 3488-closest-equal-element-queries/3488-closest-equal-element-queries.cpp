class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];

            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            // binary search
            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int m = vec.size();

            int left = vec[(pos - 1 + m) % m];
            int right = vec[(pos + 1) % m];

            int d1 = abs(q - left);
            int d2 = abs(q - right);

            int res = min({d1, d2, n - d1, n - d2});

            ans.push_back(res);
        }

        return ans;
    }
};