class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();

        for(int i = 0; i<row; i++){
            int p=col-1;
            for(int j = col-1; j>=0;j--){
                if(box[i][j]=='*'){
                    p=j-1;
                    continue;
                }
                else if(box[i][j]=='#'){
                    box[i][j]='.';
                    box[i][p]='#';
                    p--;
                }
            }
        }
        vector<vector<char>> ans(col, vector<char>(row));

        for(int i =0 ; i<row;i++){
            for(int j =0 ; j<col ; j++){
                ans[j][row-i-1]= box[i][j];
            }
        }
        return ans;
    }
};