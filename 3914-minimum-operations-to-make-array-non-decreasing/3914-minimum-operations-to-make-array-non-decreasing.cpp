class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long total = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) {
                total += (long long)(nums[i - 1] - nums[i]);
            }
        }
        return total;
    }
};