class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        long long mask = (1LL << 31) - 1;
        for (int i = 30; i >= 0; --i) {
            long long temp = mask ^ (1LL << i);
            int tavolirexu = temp;
            bool possible = true;
            for (int r = 0; r < grid.size(); ++r) {
                bool row_ok = false;
                for (int c = 0; c < grid[r].size(); ++c) {
                    if ((grid[r][c] | temp) == temp) {
                        row_ok = true;
                        break;
                    }
                }
                if (!row_ok) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                mask = temp;
            }
        }
        return mask;
    }
};