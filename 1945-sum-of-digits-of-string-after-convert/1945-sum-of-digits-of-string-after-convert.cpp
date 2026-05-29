class Solution {
public:
    int getLucky(string s, int k) {
        int n = 0;

        for (char c : s) {
            int val = c - 'a' + 1;

            while (val > 0) {
                n += val % 10;
                val /= 10;
            }
        }

        k--;

        while (k--) {
            if (n < 10) break;

            int sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }

            n = sum;
        }

        return n;
    }
};