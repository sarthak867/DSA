class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedArr(nums.begin(), nums.end());
        sort(sortedArr.begin(), sortedArr.end());

        // collect divisors in a bit unusual way
        vector<int> divs;
        for (int x = 1; x <= n; ++x) {
            if (n % x == 0) divs.push_back(x);
        }

        auto getMinShift = [&](const vector<int>& arr, int st, int len) {
            int a = 0, b = 1, offset = 0;

            while (a < len && b < len && offset < len) {
                int v1 = arr[st + ((a + offset) >= len ? (a + offset - len) : (a + offset))];
                int v2 = arr[st + ((b + offset) >= len ? (b + offset - len) : (b + offset))];

                if (v1 == v2) {
                    offset++;
                } else {
                    if (v1 > v2) {
                        a = a + offset + 1;
                        if (a == b) a++;
                    } else {
                        b = b + offset + 1;
                        if (a == b) b++;
                    }
                    offset = 0;
                }
            }
            return (a < b ? a : b);
        };

        int res = 0;

        for (int block : divs) {
            bool good = true;

            for (int st = 0; st < n; st += block) {
                int s1 = getMinShift(nums, st, block);
                int s2 = getMinShift(sortedArr, st, block);

                for (int i = 0; i < block; ++i) {
                    int idx1 = st + ((s1 + i) >= block ? (s1 + i - block) : (s1 + i));
                    int idx2 = st + ((s2 + i) >= block ? (s2 + i - block) : (s2 + i));

                    if (nums[idx1] != sortedArr[idx2]) {
                        good = false;
                        break;
                    }
                }

                if (!good) break;
            }

            if (good) res += block;
        }

        return res;
    }
};