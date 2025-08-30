class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,set<int>> row;
        map<int,set<int>> col;
        map<int,set<int>> grp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int crow=i/3;
                int ccol=j/3;
                int n=3*crow+ccol;
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    if(row[i].find(num)!=row[i].end()){
                        return false;
                    }
                    if(col[j].find(num)!=col[j].end()){
                        return false;
                    }
                    if(grp[n].find(num)!=grp[n].end()){
                        return false;
                    }
                    row[i].insert(num);
                    col[j].insert(num);
                    grp[n].insert(num);
                }

            }
        }
        return true;
        
    }
};