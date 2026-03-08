class Solution {
public:
    long long solve(string &s, int left, int right, int encCost, int flatCost) {
        
        int length = right - left + 1;
        int onesCount = 0;

        for (int i = left; i <= right; i++) {
            if (s[i] == '1') onesCount++;
        }

        if (onesCount == 0) return flatCost;

        long long totalCost = 1LL * length * onesCount * encCost;

        if (length % 2 == 0) {
            int mid = (left + right) / 2;

            totalCost = min(totalCost,
                solve(s, left, mid, encCost, flatCost) +
                solve(s, mid + 1, right, encCost, flatCost));
        }

        return totalCost;
    }

    long long minCost(string s, int encCost, int flatCost) {
        return solve(s, 0, s.size() - 1, encCost, flatCost);
    }
};