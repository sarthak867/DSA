class Solution {
public:

    bool valid(vector<string>&board, int row, int col , int n){
        for(int i =0 ; i<row; i++){
            if(board[i][col]=='Q') return 0;
        }
        for(int i = row -1,j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j]=='Q') return 0;
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j]=='Q') return 0;
        }
        return 1;
    }

    void sol(int row,int n, vector<string>&board, vector<vector<string>>&ans){
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++){
            if(valid(board, row, col, n)){
                board[row][col]='Q';
                sol(row+1,n,board,ans);
                board[row][col]='.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        sol(0,n,board,ans);
        return ans;
    }
};