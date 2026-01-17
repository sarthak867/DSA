class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        int side = 0;
        int n = b.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int x1 = max(b[i][0], b[j][0]);
                int y1 = max(b[i][1], b[j][1]);

                int x2 = min(t[i][0], t[j][0]);
                int y2 = min(t[i][1], t[j][1]);

                if (x2 > x1 && y2 > y1) {
                    int tempmin = min(x2 - x1, y2 - y1);
                    side = max(side, tempmin);
                }
            }
        }
        return 1LL * side * side;
    }
};
