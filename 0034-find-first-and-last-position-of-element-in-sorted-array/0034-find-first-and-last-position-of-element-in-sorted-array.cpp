class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = -1, end = -1, i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                s = i;
                break;
            }
        }
        if (s != -1) {
            while ( i<nums.size() && nums[i] == target ) {
                i++;
            }
            end = --i;
        }
        return {s, end};
    }
};