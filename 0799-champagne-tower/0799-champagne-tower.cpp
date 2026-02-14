class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double>> row(query_row + 2,vector<double>(query_row +2, 0.0));
        row[0][0] =(double) poured;
        
        for(int i = 0; i <= query_row; i++) {
            for(int j = i; j >=0; j--) {
                double overflow = max(0.0, row[i][j] - 1.0);
                row[i+1][j] = overflow / 2.0;
                row[i+1][j + 1] += overflow / 2.0;
            }
        }
        
        return min(1.0, row[query_row][query_glass]);
    }
};
