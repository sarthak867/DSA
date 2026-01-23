class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;

        vector<int> dup = nums;
        sort(dup.begin(), dup.end());

        while (nums != dup) {
            int minsum = INT_MAX;
            int min_index = -1;

            for (int i = 1; i < nums.size(); i++) {
                int sum = nums[i] + nums[i - 1];
                if (sum < minsum) {
                    minsum = sum;
                    min_index = i;
                }
            }

            // merge pair
            nums[min_index - 1] = minsum;
            nums.erase(nums.begin() + min_index);

            op++;

            dup = nums;
            sort(dup.begin(), dup.end());
        }

        return op;
    }
};
