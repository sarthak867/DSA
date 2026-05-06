class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();

        vector<vector<char>> ans(col, vector<char>(row, '.'));

        for(int i = 0 ; i < row; i++){
            int c = 0;
            int last = col - 1;  // 🔥 segment end

            for(int j = col - 1; j >= 0; j--){
                if(box[i][j] == '#'){
                    c++;
                }
                else if(box[i][j] == '*'){
                    ans[j][i] = '*';

                    // place stones to the right of obstacle
                    int k = last;
                    while(c > 0){
                        ans[k][i] = '#';
                        k--;
                        c--;
                    }

                    last = j - 1; // next segment
                }
            }

            // remaining stones
            int k = last;
            while(c > 0){
                ans[k][i] = '#';
                k--;
                c--;
            }
        }

        // rotate
        vector<vector<char>> res(col, vector<char>(row));
        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                res[i][j] = ans[i][row - 1 - j];
            }
        }

        return res;
    }
};