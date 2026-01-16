class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            auto it = find(nums.begin(), nums.end(), rem);

            if (it != nums.end()) {
                int j = distance(nums.begin(), it);
                if (j != i) { // ensure not same index
                    return {i, j};
                }
            }
        }
        return {};
    }
};