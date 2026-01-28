class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        string ans = "";
        int n = s.size();
        int cycle = 2 * (numRows - 1);

        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < n; ) {
                ans += s[i];

                // middle rows
                if (row != 0 && row != numRows - 1) {
                    int diag = i + cycle - 2 * row;
                    if (diag < n)
                        ans += s[diag];
                }

                i += cycle;
            }
        }
        return ans;
    }
};
