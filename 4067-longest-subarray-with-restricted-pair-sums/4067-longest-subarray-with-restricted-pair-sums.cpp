class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1;

        for (int l = 0; l < n; ++l) {
            bitset<1001> v, p;

            for (int r = l; r < n; ++r) {
                int x = nums[r];

                if (p[x] || (v & (v >> x)).any()) break;

                p |= (v << x);
                v[x] = 1;
                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};