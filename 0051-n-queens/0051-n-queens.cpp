class Solution {
public:
    unordered_map<int,bool>rowCheck;
    unordered_map<int,bool>upperLeftDiagonalCheck;
    unordered_map<int,bool>lowerLeftDiagonalCheck;
    void printSolution(vector<vector<char>>&board,int n,vector<vector<string>>&ans){
        vector<string> s;
        for(int i = 0;i<n;i++){
            string o="";
            for(int j = 0;j<n;j++){
                o.push_back(board[i][j]);
            }
            s.push_back(o);
        }
        ans.push_back(s);
    }
    bool isSafe(int row,int col,int n){
        if(rowCheck[row] == true)
            return false;
        if(upperLeftDiagonalCheck[n-1+col-row] == true){
            return false;
        }
        if(lowerLeftDiagonalCheck[row+col] == true){
            return false;
        }
        return true;
    }
    void solve(vector<vector<char>>&board,int col,int n,vector<vector<string>> &ans){
    // Base Case -> When we have placed queens in all the columns then col will go to n
        if(col >= n){
            printSolution(board,n,ans);
            return;
        }
        // Just Solve one case 
        // In every row, place the queen
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,n)){
                // Place it then
                board[row][col] = 'Q'; // 1 means queen, 0 means no queen
                // Map modification
                rowCheck[row] = true;
                upperLeftDiagonalCheck[n-1+col-row] = true;
                lowerLeftDiagonalCheck[row+col] = true;
                // Recursive call for col + 1
                solve(board,col+1,n,ans);
                // Backtracking -> Create original state
                board[row][col] = '.'; // Queen removed 
                // Map modification -> recreate original state
                rowCheck[row] = false;
                upperLeftDiagonalCheck[n-1+col-row] = false;
                lowerLeftDiagonalCheck[row+col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>>board(n,vector<char>(n,'.')); 
        int col = 0;
        solve(board,col,n,ans);
    return ans;   
    }
};