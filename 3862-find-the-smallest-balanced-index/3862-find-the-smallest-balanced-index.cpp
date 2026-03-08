class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> p(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] != 0 && p[i + 1] > LLONG_MAX / nums[i]) {
                p[i] = LLONG_MAX; // mark as overflow
            } else {
                p[i] = p[i + 1] * nums[i];
            }
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum == p[i + 1])
                return i;
            sum += nums[i];
        }
        return -1;
    }
};