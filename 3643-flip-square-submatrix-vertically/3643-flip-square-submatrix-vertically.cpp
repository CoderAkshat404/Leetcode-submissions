class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i=x;
        int j=x+k-1;
        while(i<j){
            for(int p=y;p<=y+k-1;p++){
                swap(grid[i][p],grid[j][p]);   
            }
            i++;
            j--;
        }
        return grid;
        
    }
};