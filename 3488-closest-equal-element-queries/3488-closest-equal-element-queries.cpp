class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];          // save original index
            int val = nums[q];
            auto &vec = mp[val];

            if (vec.size() == 1) {
                queries[i] = -1;
                continue;
            }

            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            int m = vec.size();

            int left = vec[(pos - 1 + m) % m];
            int right = vec[(pos + 1) % m];

            int d1 = abs(q - left);
            int d2 = abs(q - right);

            queries[i] = min({d1, d2, n - d1, n - d2});
        }

        return queries;
    }
};