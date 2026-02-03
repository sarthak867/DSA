class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool p1 = 0, p2 = 0, p3 = 0;
        int i = 0;
        int n = nums.size();

        while (i + 1 < n && nums[i + 1] > nums[i]) {
            p1 = 1;
            i++;
        }
        if(!p1) return false;
        while (i + 1 < n && nums[i + 1] < nums[i]) {
            p2 = 1;
            i++;
        }
        if(!p2) return false;
        while (i + 1 < n && nums[i + 1] > nums[i]) {
            p3 = 1;
            i++;
        }
        if(!p3) return false;

        return (i == n - 1);
    }
};
