
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int sz = nums.size();
        vector<int> e(sz + 1), o(sz + 1);

        for (int i = sz - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                e[i] = e[i + 1] + 1;
                o[i] = o[i + 1];
            } else {
                o[i] = o[i + 1] + 1;
                e[i] = e[i + 1];
            }
        }

        vector<int> ans(sz);
        for (int i = 0; i < sz; i++) {
            if (nums[i] % 2 == 0) {
                ans[i] = o[i + 1];
            } else {
                ans[i] = e[i + 1];
            }
        }

        return ans;
    }
};