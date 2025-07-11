class Solution {
public:
    unordered_map<int,int> row;
    unordered_map<int,int> upleftdiag;
    unordered_map<int,int> loleftdiag;
    vector<vector<string>> ans;

    void rec(int col, vector<string> board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++){
            if(row[i] == 0 && upleftdiag[col + i] == 0 && loleftdiag[n - 1 + (col - i)] == 0){
                board[i][col] = 'Q';
                row[i] = 1;
                upleftdiag[col + i] = 1;
                loleftdiag[n - 1 + (col - i)] = 1;

                rec(col + 1, board, n);

                board[i][col] = '.';
                row[i] = 0;
                upleftdiag[col + i] = 0;
                loleftdiag[n - 1 + (col - i)] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        row.clear();
        upleftdiag.clear();
        loleftdiag.clear();
        ans.clear();

        vector<string> board(n, string(n, '.'));
        rec(0, board, n);
        return ans;
    }
};
