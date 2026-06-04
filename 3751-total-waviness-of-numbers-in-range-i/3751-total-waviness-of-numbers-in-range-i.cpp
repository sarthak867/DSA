class Solution {
public:
    int pv(int i) {
        string s = to_string(i);
        int c = 0;
        for (int i = 1; i < s.size() - 1; i++) {
            if ((s[i] > s[i + 1] && s[i] > s[i - 1]) ||
                (s[i] < s[i + 1] && s[i] < s[i - 1]))
                c++;
        }
        return c;
    }

    int totalWaviness(int num1, int num2) {
        if (num2 <= 100)
            return 0;
        int c = 0;
        while (num1 <= num2) {
            c += pv(num1);
            num1++;
        }
        return c;
    }
};
