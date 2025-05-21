class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,bool> r;
        unordered_map<int,bool> c;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    r[i]=true;
                    c[j]=true;
                }
            }
        }
        for(auto i:r){
            for(int j=0;j<matrix[0].size();j++){
                matrix[i.first][j]=0;
            }
        }
        for(auto i:c){
            for(int j=0;j<matrix.size();j++){
                matrix[j][i.first]=0;
            }
        }
        
        
    }
};