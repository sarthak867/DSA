class Solution {
public:
    string decodeCiphertext(string e, int rows) {
        int l = e.length();
        int col = l / rows;

        string ans = "";

        int i = 0, j = 0;

        // start from each column of first row
        for (j = 0; j < col; j++) {
            i = 0;
            int k = j;

            // diagonal traversal
            while (i < rows && k < col) {
                ans += e[i * col + k];
                i++;
                k++;
            }
        }

        // remove trailing spaces
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};