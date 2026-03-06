class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int len = s.length();

        long long result = 0;
        long long power = 9;

        for (int i = 1; i < len; i++) {
            result += power;
            power *= 9;
        }

        bool isValid = true;

        for (int i = 0; i < len; i++) {
            int digit = s[i] - '0';
            if (digit == 0) {
                isValid = false;
                break;
            }
            int remaining = len - i - 1;
            long long combinations = 1;
            for (int j = 0; j < remaining; j++) {
                combinations *= 9;
            }
            result += (long long)(digit - 1) * combinations;
        }
        if (isValid) {
            result++;
        }
        return result;
    }
};