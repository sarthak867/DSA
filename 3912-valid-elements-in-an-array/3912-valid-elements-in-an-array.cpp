class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int sz = nums.size();
        vector<int> l(sz), r(sz), ans;

        l[0] = INT_MIN;
        for (int i = 1; i < sz; i++) {
            l[i] = max(l[i-1], nums[i-1]);
        }

        r[sz-1] = INT_MIN;
        for (int i = sz - 2; i >= 0; i--) {
            r[i] = max(r[i+1], nums[i+1]);
        }

        for (int i = 0; i < sz; i++) {
            if (i == 0 || i == sz - 1) {
                ans.push_back(nums[i]);
            } else if (nums[i] > l[i] || nums[i] > r[i]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};