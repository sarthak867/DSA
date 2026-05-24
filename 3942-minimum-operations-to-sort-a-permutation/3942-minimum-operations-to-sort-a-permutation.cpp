class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int zero = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        bool inc = true;
        for (int i = 0; i < n; i++) {
            int idx = (zero + i) % n;

            if (nums[idx] != i) {
                inc = false;
                break;
            }
        }

        if (inc) {
            return min(zero, n - zero + 2);
        }

        bool dec = true;
        for (int i = 0; i < n; i++) {
            int idx = (zero + i) % n;
            int ex = (n - i) % n;

            if (nums[idx] != ex) {
                dec = false;
                break;
            }
        }

        if (dec) {
            return min(zero + 2, n - zero);
        }

        return -1;
    }
};