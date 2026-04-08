class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int ans = 0;
        for (int j = 0; j < q.size(); j++) {
            for (int i = q[j][0]; i <= q[j][1]; i += q[j][2]) {
                nums[i] = (1LL * nums[i] * q[j][3]) % (int)(1e9 + 7);
            }
        }
        for (int i : nums) {
            ans = ans ^ i;
        }
        return ans;
    }
};