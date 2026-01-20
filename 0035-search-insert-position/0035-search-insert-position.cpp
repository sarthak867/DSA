class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = std::find(nums.begin(), nums.end(), target);
        if (it != nums.end()) {
            return distance(nums.begin(), it);
        } else {
            int left = 0, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            return left;
        }
        return nums.size();
    }
};